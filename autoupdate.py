
import httplib,urllib,threading

body = "{\"task\":\"autoupdate\",\
\"token\":\"ae873897a0a9a2af40d54506eeb43e0b1dafe8c95e7f02f0e11098ddfab21245ee0289baada9bd8ca2c386c40036523b7926f07dd201b6aa7926f07dd201b6aa7926f07dd201b6aa7926f07dd201b6aa7926f07dd201b6aa7926f07dd201b6aa7926f07dd201b6aa7926f07dd201b6aa7926f07dd201b6aa7926f07dd201b6aa\",\
\"patch_name\":\"patch_9.1.0001.zip\" \
}"

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

