a=int(input())
b=int(input())
_b=list(map(int,str(b)))
for i in reversed(_b):
    print(a*i)
print(a*b)