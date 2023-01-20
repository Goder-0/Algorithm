max=0
list=[]
for i in range(9):
    n=int(input())
    if n>max:
        max=n
    list.append(n)
print(max)
print(list.index(max)+1)