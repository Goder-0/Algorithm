right=[1,1,2,2,2,8]
list=list(map(int,input().split()))
print(*[righti - listi for righti,listi in zip(right,list)])
