list=["c=","c-","dz=","d-","lj","nj","s=","z="]
s=input()
count=len(s)
for al in list:
    count-=s.count(al)
print(count)