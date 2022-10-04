import sys
sys.setrecursionlimit(10**6)


n, m = map(int, input().split())
lns = [list(input()) for i in range(0, n)]

check = lambda y, x: 0 <= y < n and 0 <= x < m

directions = [[-1, 0], [1, 0], [0, -1], [0,1]]
visited = [[False for j in range(0, m)] for i in range(0, n)]


def dfs(y, x):
    answer = [0, 0]
    if lns[y][x] == 'o':
        answer[0] += 1
    if lns[y][x] == 'v':
        answer[1] += 1
        
    visited[y][x] = True
        
    for i in directions:
        ny, nx = y + i[0], x + i[1]
        if check(ny, nx) and not visited[ny][nx] and lns[ny][nx] != '#':
            temp = dfs(ny, nx)
            answer[0] += temp[0]
            answer[1] += temp[1]
    
    return answer


answer = [0, 0]
for i in range(0, len(lns)):
    for j in range(0, len(lns[i])):
        if lns[i][j] != '#' and not visited[i][j]:
            temp = dfs(i, j)
            
            if temp[0] <= temp[1]:
                answer[1] += temp[1]
            else:
                answer[0] += temp[0]

print(f"{answer[0]} {answer[1]}")
