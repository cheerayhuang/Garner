module(...)

local CreateIndexSql = [[ 
CREATE TABLE IF NOT EXISTS %s (
    entity_id VARCHAR(32) NOT NULL UNIQUE,
    %s VARCHAR(1024) NOT NULL, 
    PRIMARY KEY(%s, entity_id)
) ENGINE=InnoDB; ]]

function CreateIndex(property)
    local tableName = property.."_index"
    local sql = string.format(CreateIndexSql, tableName, property, property)

    return sql
end
