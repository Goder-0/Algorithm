from collections import Counter
N=int(input())
result=0
for i in range(N):
    s=input()
    countDic=Counter(s)
    count=0
    preC=''
    r=0
    for c in s:
        if preC!=c:
            if countDic[preC]!=count:
                r=-1
                break
            preC=c
            count=1
        else:
            count+=1
    if r==0:
        result+=1
print(result)
    