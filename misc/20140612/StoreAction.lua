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

    self.getMysql = function () 
        if self.app then 
          return self.app:getMysql              
        end

        return nil
    end
end


function StoreAction:SaveObjAction(data) 
    assert(type(data) == "table", "data should be a table!")
    local mysql = self:getMysql()
    if mysql == nil then 
        throw(ERR_SERVER_MYSQL_ERROR, "connect to mysql failed.")
    end
    
    local rawData = data.rawdata
    if rawData == nil or type(rawdata) ~= "table" then 
        throw(ERR_SERVER_INVALID_PARAMETERS, "param(rawdata) is missed.")
    end

    params = self:ConstructParams(rawdata)
    mysql.insert("counter", params) 
end 

function StoreAction:UpdateObjAction(data)
end

function StoreAction:DeleteObjAction(data)
end

function StoreAction:ConstructParams(rawdata)
    local sha1_bin
    local bas64
    if ngx then 
        sha1_bin = ngx.sha1_bin
        base64 = ngx.encode_base64
    else 
        throw(ERR_SERVER_UNKNOWN_ERROR, "ngx is nil")
    end

    local body = {}
    for _, t in pairs(rawdata) do 
        if t.index == 1 then 
        end 

        for k, v in pairs(t) do
            body[k] = v
        end
    end 
    local id = sha1_bin(json.encode(body))

    return {id=id, body=body} 
end

return StoreAction

