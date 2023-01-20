import sys
N,X=map(int,sys.stdin.readline().split())
A=list(map(int,sys.stdin.readline().split()))
[print(i,end=" ") for i in A if i<X ]