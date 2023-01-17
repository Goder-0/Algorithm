list=list(map(int,input().split()))
price=0
for i in list:
    if list.count(i)==3:
        price=10000+i*1000
        break
    elif list.count(i)==2:
        price=1000+i*100
        break
    else:
        if price<i*100:
            price=i*100

print(price)