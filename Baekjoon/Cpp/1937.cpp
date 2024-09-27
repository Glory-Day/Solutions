#include <iostream>
#include <climits>
#include <cmath>
#include <queue>
#include <algorithm>

using namespace std;

struct point { int x; int y; };

const point directions[4] = { { 1,0 },{ -1,0 },{ 0,1 },{ 0,-1 } };

int n;
int matrix[500][500];
int caches[500][500];

const bool check(const int x, const int y)
{
    return 0 <= y && y < n && 0 <= x && x < n;
}

const int dfs(const int x, const int y)
{
    if (0 < caches[y][x])
    {
        return caches[y][x];
    }
    
    caches[y][x] = 1;

    for (const auto& d: directions)
    {
        int nx = x + d.x;
        int ny = y + d.y;

        if (check(nx, ny) && matrix[y][x] < matrix[ny][nx])
        {
            caches[y][x] = max(caches[y][x], dfs(nx, ny) + 1);

            dfs(nx, ny);
        }
    }

    return caches[y][x];
}

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }

    int answer = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            answer = max(answer, dfs(j, i));
        }
    }

    cout << answer;

    return 0;
}