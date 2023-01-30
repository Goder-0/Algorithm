import sys
a,b=map(str,sys.stdin.readline().strip().split())
a=int("".join(reversed(a)))
b=int("".join(reversed(b)))
[print(a) if a>b else print(b)]