def d():
    numbers=set(range(1,10001))
    for n in range(1,10001):
        n_list=[int(a) for a in str(n)]
        sum=n
        for i in n_list:
            sum+=i
        numbers.discard(sum)
    [print(i) for i in numbers]
d()