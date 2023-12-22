cache = [202021, 20202021, 202002021, 202012021, 202022021, 202032021, 202042021, 202052021, 202062021, 202072021, 202082021, 202092021]

t = int(input())
for _ in range(t):
    n = int(input())
    arr = list(map(int, input().split()))

    arr.sort()

    dict = {}
    for i in arr:
        dict[i] = dict.get(i, 0) + 1
    
    answer = 0
    for i in arr:
        for j in cache:
            a = j - i
            if a in dict:
                answer += dict[a]
                if a == i:
                    answer -= 1
    
    print(answer // 2)