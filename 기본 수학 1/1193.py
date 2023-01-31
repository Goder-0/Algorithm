X=int(input())
sum=2
while  X>sum*(sum-1)/2:
    sum+=1
a=int(sum*(sum-1)/2-X+1)
print(f'{sum-a}/{a}' if sum%2==1 else f'{a}/{sum-a}')