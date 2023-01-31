import sys
import math
A,B,V=map(int,sys.stdin.readline().split())
days=math.ceil((V-A)/(A-B))
print(days+1)