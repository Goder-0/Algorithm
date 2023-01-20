import sys
n=int(input())
for i in range(n):
    score=0
    line=sys.stdin.readline().strip()
    s=0
    for i in line:
        if i=="O":
            s+=1
        elif i=="X":
            s=0
        score+=s
    print(score)
