import sys
n= int(input())
r=[]
for i in range(n):
    a,b=map(int,sys.stdin.readline().split())
    r.append(a+b)
for i in r:
    print(i)