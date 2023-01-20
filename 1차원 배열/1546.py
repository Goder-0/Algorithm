import sys
n=int(input())
scores=list(map(int,sys.stdin.readline().split()))
max=0
for i in scores:
    if i>max:
        max=i
sum=0
for i in scores:
    sum+=i/max*100
print(sum/n)