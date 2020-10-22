#!/usr/bin/python3
# -*- coding:utf-8 -*-
from scapy.all import *
dpkt=sniff(iface = "wlp0s20f3",count = 100)
wrpcap("a.pcap",dpkt)
print(dpkt)



