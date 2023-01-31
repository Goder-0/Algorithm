n=int(input())
k=0
while True:
    if n>3*k*(k+1)+1:k+=1
    else: break
print(k+1)