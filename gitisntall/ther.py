#! /usr/bin/env python
# coding=utf-8
#================================================================
#   Copyright (C) 2020 * Ltd. All rights reserved.
#   
#   File name   : ther.py
#   Author      : longbin
#   Created date: 2020-05-18 16:20:41
#   Description : 
#
#================================================================

import threading
def thrad_job(asd):
    print("hello world!",asd)
def main():
    asd = threading.Thread(target=thrad_job,args=('asdf',))
    asd.start()
    pass
main()
