#! /usr/bin/env python
# coding=utf-8
#================================================================
#   Copyright (C) 2020 * Ltd. All rights reserved.
#   
#   File name   : gitinstall.py
#   Author      : longbin
#   Created date: 2020-05-18 14:04:31
#   Description : 
#
#================================================================


#!/usr/bin/env python
# cooding=utf-8

import requests
import re
import json
import sys
def main():
    Str = ""

    URL = "https://api.toolnb.com/Tools/Api/githubjiasu.html" 

    Head = {
           # '\:authority':'api.toolnb.com',
           # '\:method':'POST',
           # ':path':'/Tools/Api/githubjiasu.html',
           # ':scheme':'https',
            'accept':'application/json, text/javascript, */*; q=0.01',
            'accept-encoding':'gzip, deflate, br',
            'accept-language':'zh-CN,zh;q=0.9',
            'content-length':'55',
            'content-type':'application/x-www-form-urlencoded; charset=UTF-8',
            #'origin: https':'//www.toolnb.com',
            #'referer: https':'//www.toolnb.com/tools/githubjiasu.html',
            'sec-fetch-dest':'empty',
            'sec-fetch-mode':'cors',
            'sec-fetch-site':'same-site',
            'user-agent':'Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/81.0.4044.138 Safari/537.36'
            }
    #get URl
    Str = sys.argv[1]
    date = {
            'url': Str
            }
    res = requests.post(url = URL,data=date,headers = Head)
    res = res.content.decode("utf-8")
    #jsoh 
    strSine = json.loads(res)
    print(strSine)
    url = strSine['data']['file'] #zip url
    print("URL:",url)
    File_Name = strSine['data']
    #print(strSine)
pass
main()
