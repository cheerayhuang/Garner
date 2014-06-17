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

        ["id" : "xxxxxxx"]  --for delete/update operation
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

    local rawData = data.rawdata
    if rawData == nil or type(rawData) ~= "table" then 
        throw(ERR_SERVER_INVALID_PARAMETERS, "param(rawdata) is missed.")
    end

    params = self:ConstructParams(rawData)
    local ok, err = mySql:insert("counter", params) 
    if err then 
        throw(ERR_SERVER_MYSQL_ERROR, "insert data failed: %s", err)
    end 

    self.OK.id = params.id
    return self.OK 
end 

function StoreAction:UpdateObjAction(data)
    assert(type(data) == "table", "data should be a table!")
    local mySql = self.Mysql
    if mySql == nil then 
        throw(ERR_SERVER_MYSQL_ERROR, "connect to mysql failed.")
    end

    local rawData = data.rawdata
    if rawData == nil or type(rawData) ~= "table" then 
        throw(ERR_SERVER_INVALID_PARAMETERS, "param(rawdata) is missed.")
    end

    local id = data.id
    if id == nil or type(id) ~= "string" then 
        throw(ERR_SERVER_INVALID_PARAMETERS, "param(id) is missed.")
    end

    params = self:ConstructParams(rawData)
    local ok, err = mySql:update("counter", params, {id=id}) 
    if err then 
        throw(ERR_SERVER_MYSQL_ERROR, "update data failed: %s", err)
    end 

    self.OK.id = params.id
    return self.OK
end

function StoreAction:DeleteObjAction(data)
    assert(type(data) == "table", "data should be a table!")
    local mySql = self.Mysql
    if mySql == nil then 
        throw(ERR_SERVER_MYSQL_ERROR, "connect to mysql failed.")
    end

    local id = data.id
    if id == nil or type(id) ~= "string" then 
        throw(ERR_SERVER_INVALID_PARAMETERS, "param(id) is missed.")
    end

    local ok, err = mySql:del("counter", {id=id}) 
    if err then 
        throw(ERR_SERVER_MYSQL_ERROR, "delete data failed: %s", err)
    end 

    self.OK.id = id
    return self.OK
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
    local id = base64(sha1(json.encode(body)))

    return {id=id, body=json.encode(body)} 
end

return StoreAction

