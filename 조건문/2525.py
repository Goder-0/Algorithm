hour,min=map(int,input().split())
finish=int(input())
min+=finish
if min>=60:
    hour+=min//60
    min%=60
if hour>=24:
    hour-=24
print(hour,min)