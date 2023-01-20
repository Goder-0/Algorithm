n=int(input())
count=0
new_num=-1
list=[int(x) for x in str(n)]
while n!=new_num:
    if len(list)==1:
        list.insert(0,0)
    a,b=list
    new_num=b*10+(a+b)%10
    list=[int(x) for x in str(new_num)]
    count+=1
print(count)