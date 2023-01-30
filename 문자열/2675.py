import sys
T=int(input())

for i in range(T):
    R,S=map(str,sys.stdin.readline().rstrip().split())
    [print(s,end="")  for s in S for j in range(int(R))]
    print()