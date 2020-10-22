str = "BA BBB BA BBA ABA AB B AAB ABAA AB B AA BBB BA AAA BBAABB AABA ABAA AB BBA BBBAAA ABBBB BA AAAB ABBBB AAAAA ABBBB BAAA ABAA AAABB BB AAABB AAAAA AAAAA AAAAB BBA AAABB"
st = ""
for strn in str:
    if(strn == "B"):
        strn = '-'
    if(strn == "A"):
        strn = '.'
    st += strn

print(type(strn))
print(st)
