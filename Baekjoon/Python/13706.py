n = int(input());

low = 1
high = n;
while True:
    mid = (low + high) // 2;
    
    if mid ** 2 == n:
        print(mid)
        break
    elif mid ** 2 > n:
        high = mid - 1
    else:
        low = mid + 1