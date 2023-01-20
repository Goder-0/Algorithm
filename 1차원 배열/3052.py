r=[]
for i in range(10):
    a=int(input())
    r.append(a%42)
print(len(set(r)))