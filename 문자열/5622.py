list=["ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"]
s=input()
sum=0
for i in s:
    for j in range(len(list)):
        if list[j].find(i)>-1:
            sum+=j+3
print(sum)
