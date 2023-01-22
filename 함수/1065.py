def isHan(n):
    list=[int(a) for a in str(n)]
    if len(list)==1:
        return True
    d=list[1]-list[0]
    for i in range(len(list)-1):
        if d!=list[i+1]-list[i]:
            return False
    return True

n=int(input())
count=0
for i in range(1,n+1):
    if isHan(i):
        count+=1
print(count)