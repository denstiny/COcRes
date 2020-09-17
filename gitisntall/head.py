#! /usr/bin/env python
# coding=utf-8
#================================================================
#   Copyright (C) 2020 * Ltd. All rights reserved.
#   
#   File name   : head.py
#   Author      : longbin
#   Created date: 2020-05-18 17:33:53
#   Description : als
#
#================================================================

import requests
url = "https://images2015.cnblogs.com/blog/930081/201702/930081-20170218114752644-1895574791.png"
headers = {"Range":"bytes=123-3000"}
f = requests.get(url=url,headers=headers)
with open("name.jpg",'ab+') as fs:
    fs.write(f.content)
    
