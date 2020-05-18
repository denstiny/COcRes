#!/usr/bin/env python
# cooding=utf-8
import requests
import re
import json
import sys
def main():
    Str = ""

    URL = "https://api.toolnb.com/Tools/Api/githubjiasu.html" 

    #get URl
    Str = sys.argv[1]
    print(Str)
    date = {
            'url': Str
            }
    res = requests.post(url = URL,data = date)
    res = res.content.decode("utf-8")

    #jsoh 
    strSine = json.loads(res)
    print(strSine)

    pass
main()
