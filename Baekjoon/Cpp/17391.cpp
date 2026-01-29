#include <iostream>
#include <climits>
#include <vector>
#include <queue>
#include <utility>
#include <functional>

#define FAST_IO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int bfs(vector<vector<int>>& v)
{
    int n = (int)v.size();
    int m = (int)v[0].size();
    vector<vector<int>> cache(n, vector<int>(m, INT_MAX));
    cache[0][0] = 0;

    queue<pair<pair<int, int>, int>> q;
    q.push({ { 0,0 },0 });

    auto check = [&](int y, int x)
    {
        return 0 <= y && y < n && 0 <= x && x < m;
    };

    while (q.empty() == false)
    {
        auto nd = q.front();
        q.pop();
        
        int y = nd.first.first;
        int x = nd.first.second;
        int cst = nd.second;

        if (y == n - 1 && x == m - 1)
        {
            break;
        }

        int d = v[y][x];
        for (int i = 1; i <= d; i++)
        {
            int ny = y + i;
            int nx = x + i;
            int ncst = cst + 1;

            if (check(ny, x) && cache[ny][x] > ncst)
            {
                cache[ny][x] = ncst;

                q.push({ { ny,x },ncst });
            }

            if (check(y, nx) && cache[y][nx] > ncst)
            {
                cache[y][nx] = ncst;

                q.push({ { y,nx },ncst });
            }
        }
    }

    return cache[n - 1][m - 1];
}

int main()
{
    FAST_IO;

    int n, m;
    cin >> n >> m;

    vector<vector<int>> v(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
        }
    }

    int answer = bfs(v);

    cout << answer;

    return 0;
}