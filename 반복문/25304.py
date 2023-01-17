price=int(input())
n=int(input())
calc=0
for i in range(n):
    p,c=map(int,input().split())
    calc+=p*c
if price==calc:
    print("Yes")
else:
    print("No")