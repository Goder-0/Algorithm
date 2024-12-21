def solution(l, r):
    answer = []
    
    for i in range(l,r+1):
        flag=True
        for j in str(i):
            if j not in '05':
                flag=False
                break
        if flag:
            answer.append(i)
    
    if not answer:
        answer.append(-1)
    
    return answer