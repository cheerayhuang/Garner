local StoreAction = class("StoreAction", cc.server.ActionBase)

function StoreActoin:SaveObjAction(data) 
    assert(type(data) == "table", "data should be a table!")
    local mysql = self:getMysql()
    
    local sha1_bin = nil
    if ngx then 
        sha1_bin = ngx.sha1_bin
    else 
        throw(ERR_SERVER_UNKNOWN_ERROR, "ngx is nil")
    end 

    local rawData = data.rawdata
    if rawData == nil then 
        throw(ERR_SERVER_INVALID_PARAMETERS, "param(rawdata) is missed.")
    end


    ConstructData()

end 

function StoreAction:UpdateObjAction(data)
end

function StoreAction:DeleteObjAction(data)
end

local function ConstructData()

end

return StoreAction

