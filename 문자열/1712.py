import sys
import math
A,B,C = map(int,sys.stdin.readline().split())
if C-B>0:
    print(math.trunc(A/(C-B))+1)
else:
    print(-1)