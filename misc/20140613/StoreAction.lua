local StoreAction = class("StoreAction", cc.server.ActionBase)

--[[
--REQ
    { 
        "action" : "actionname", 
        "rawdata": {
            { "key1" : "val1"}, 
            { "key2" : "val2", "index" : 1},
            ...
            {"key_n" : "val_n"}
        }
    }
--
--]]

function StoreAction:ctor(app)
    self.super:ctor(app)

    self.Mysql = nil
    self.Redis = nil
    if self.app then 
        self.Mysql = self.app.getMysql(self.app)
        self.Redis = self.app.getRedis(self.app)
    end

    self.OK = {success=1}
end


function StoreAction:SaveObjAction(data) 
    assert(type(data) == "table", "data should be a table!")
    local mySql = self.Mysql
    if mySql == nil then 
        throw(ERR_SERVER_MYSQL_ERROR, "connect to mysql failed.")
    end

    for k in pairs(mySql) do 
        echoInfo("[%s]", k)
    end 

    local rawData = data.rawdata
    if rawData == nil or type(rawData) ~= "table" then 
        throw(ERR_SERVER_INVALID_PARAMETERS, "param(rawdata) is missed.")
    end

    params = self:ConstructParams(rawData)
    local ok, err = mySql:insert("counter", params) 
    if err then 
        throw(ERR_SERVER_MYSQL_ERROR, "insert data failed: %s", err)
    end 

    return self.OK 
end 

function StoreAction:UpdateObjAction(data)
end

function StoreAction:DeleteObjAction(data)
end

function StoreAction:ConstructParams(rawData)
    local sha1_bin
    local bas64
    if ngx then 
        sha1 = ngx.sha1_bin
        base64 = ngx.encode_base64
    else 
        throw(ERR_SERVER_UNKNOWN_ERROR, "ngx is nil")
    end

    local body = {}
    for _, t in pairs(rawData) do 
        if t.index == 1 then 
        end 

        for k, v in pairs(t) do
            body[k] = v
        end
    end 
    local id = sha1(json.encode(body))

    return {id=base64(id), body=body} 
end

return StoreAction

