hour,min=map(int,input().split())
if min>=45:
    print(hour, min-45)
else:
    if hour>0:
        print(hour-1, min+15)
    else:
        print(hour+23,min+15)