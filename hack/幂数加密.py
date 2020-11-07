a="8842101220480224404014224202480122"
a=a.split("0")
flag=''
for i in range(0,len(a)):
     str = a[i]
     list=[]
     sum=0
     for j in str:
        list.append(j)
        length = len(list)
     for k in range(0,length):
        sum+=int(list[k])
     flag+=chr(sum+64)
print(flag)

