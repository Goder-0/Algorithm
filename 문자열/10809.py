s=input()
l=[-1 for _ in range(26)]
for index in range(len(s)):
    if l[ord(s[index])-97]==-1:
        l[ord(s[index])-97]=index
[print(i, end=" ") for i in l]