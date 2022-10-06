import sys;

input = sys.stdin.readline

for i in range(3):
    n = int(input());
    
    arr = [int(input()) for _ in range(n)]
    
    if sum(arr) == 0: print(0)
    elif sum(arr) > 0: print('+');
    else: print('-');