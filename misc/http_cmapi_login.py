
import httplib,urllib,threading

body = "{\"task\":\"login\",\
\"id\":\"admin\",\
\"password\":\"1234\",\
\"clientver\":\"8.4\",\
\"targetid\":\"admin\",\
\"dbuser\":\"dba\",\
\"dbpasswd\":\"\"}"

print body

headers = {"Accept": "text/plain;charset=utf-8"}
conn = httplib.HTTPConnection("10.34.135.83", 8003)
#conn = httplib.HTTPConnection("localhost", 8003)

for i in range(1):
    conn.request("POST", "/cm_api", body, headers)
    r = conn.getresponse()
    print (r.status, r.reason)
    print (r.read())
conn.close()

