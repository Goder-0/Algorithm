import sys
T=int(input())
for i in range(T):
    H,W,N=map(int,sys.stdin.readline().split())
    if N%H!=0:
        print('{}{:02d}'.format(N%H,N//H+1))
    else:
        print('{}{:02d}'.format(N%H+H,N//H))