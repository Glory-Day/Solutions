#include <iostream>
#include <queue>
#include <utility>

using namespace std;

using pii = pair<int, int>;

const pii directions[4] = { { 1,0 },{ 0,1 },{ -1,0 },{ 0,-1 } };

int n, m;
char matrix[600][600];
bool visited[600][600];

const bool check(const int& y, const int& x)
{
    return 0 <= y && y < n && 0 <= x && x < m;
}

const int bfs(const int& y, const int& x)
{
    queue<pii> q;
    q.push({ y,x });

    visited[y][x] = true;

    int count = 0;
    while (q.empty() == false)
    {
        auto p = q.front();
        q.pop();

        for (const auto& d: directions)
        {
            int ny = p.first + d.first;
            int nx = p.second + d.second;

            if (check(ny, nx) && visited[ny][nx] == false && matrix[ny][nx] != 'X')
            {
                if (matrix[ny][nx] == 'P')
                {
                    count++;
                }

                visited[ny][nx] = true;
                q.push({ ny,nx });
            }
        }
    }

    return count;
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }

    int y, x;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 'I')
            {
                y = i;
                x = j;
            }
        }
    }

    int answer = bfs(y, x);
    if (0 < answer)
    {
        cout << answer;
    }
    else
    {
        cout << "TT";
    }

    return 0;
}