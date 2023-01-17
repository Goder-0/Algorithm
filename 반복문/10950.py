count=int(input())
list=[]
for i in range(count):
    a,b=map(int,input().split())
    list.append((a,b))
for a,b in list:
    print(a+b)