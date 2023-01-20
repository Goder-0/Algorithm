import sys
n=int(input())
list=list(map(int,sys.stdin.readline().split()))
max=list[0]
min=list[0]
for i in list:
    if i>max:
        max=i
    if i<min:
        min=i
print(min, max)