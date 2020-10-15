import requests
from lxml import etree
URL = "https://zh.wikipedia.org/wiki/TCP/UDP%E7%AB%AF%E5%8F%A3%E5%88%97%E8%A1%A8"
prox = {"http": "http://127.0.0.1:8889", "https": "https://127.0.0.1:8889"}
str = requests.get(URL, proxies=prox)
str = str.text
dom = etree.HTML(str)
tes = dom.xpath('//tbody')
print(tes)
