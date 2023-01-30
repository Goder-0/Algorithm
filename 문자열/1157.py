from collections import Counter

s=input().strip().upper()
count=dict(Counter(s))
values=[i for i in count.values()]
values.sort(reverse=True)
max=values[0]
res=[i for i,v in count.items() if v==max]
if len(res)>1:
    print("?")
else:
    print(res[0])