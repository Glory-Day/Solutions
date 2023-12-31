import math

t = int(input())

while t != 0:
    n, k = map(int, input().split())
    l = list(map(int, input().split()))

    a = 4 * n
    b = 0
    c = 0
    for i in l:
        b = b + 4 * i
        c = c + i * i

    s = 1
    e = 1e9
    answer = 0
    while s <= e:
        x = int((s + e) // 2)
        tmp = (a * x * x) + (b * x) + c

        if tmp == k:
            answer = x
            break
        elif tmp < k:
            s = x + 1
        else:
            e = x - 1

    print(answer)

    t = t - 1