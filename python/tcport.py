import requests
URL = "https://zh.wikipedia.org/wiki/TCP/UDP%E7%AB%AF%E5%8F%A3%E5%88%97%E8%A1%A8"
str = requests.get(URL)
print(str.text)
