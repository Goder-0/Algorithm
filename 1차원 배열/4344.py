import sys
c=int(input())
list=[list(map(int,sys.stdin.readline().split())) for x in range(c)]
for data in list:
    n=data[0]
    del data[0]
    sum=0
    for i in data:
        sum+=i
    count=0
    for i in data:
        if i>sum/n:
            count+=1
    print("{:.3f}%".format(count/n*100))