#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <functional>

using namespace std;

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY)
{
    int answer = 0;

    pair<int, int> directions[4] = { { -1,0 },{ 1,0 },{ 0,-1 },{ 0,1 } };

    static int board[102][102];
    fill(&board[0][0], &board[0][0] + 102 * 102, -1);

    int size = (int)rectangle.size();
    for (int i = 0; i < size; i++)
    {
        int ax = rectangle[i][0] * 2;
        int ay = rectangle[i][1] * 2;
        int bx = rectangle[i][2] * 2;
        int by = rectangle[i][3] * 2;

        for (int y = ay; y <= by; y++)
        {
            for (int x = ax; x <= bx; x++)
            {
                if (x == ax || x == bx || y == ay || y == by)
                {
                    if (board[y][x])
                    {
                        board[y][x] = 1;
                    }
                }
                else
                {
                    board[y][x] = 0;
                }
            }
        }
    }

    characterX *= 2;
    characterY *= 2;
    itemX *= 2;
    itemY *= 2;

    queue<pair<int, int>> q;
    bool visited[102][102] = {false};
    int cache[102][102] = { 0 };
    
    q.push({characterY, characterX});
    visited[characterY][characterX] = true;
    
    while (q.empty() == false)
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        
        if (y == itemY && x == itemX)
        {
            return cache[y][x] / 2;
        }
        
        for (const auto& direction: directions)
        {
            int ny = y + direction.first;
            int nx = x + direction.second;
            
            if (0 <= ny && ny < 102 && 0 <= nx && nx < 102)
            {
                if (board[ny][nx] == 1 && visited[ny][nx] == false)
                {
                    visited[ny][nx] = true;
                    cache[ny][nx] = cache[y][x] + 1;

                    q.push({ny, nx});
                }
            }
        }
    }

    return answer;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> rectangle(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> rectangle[i][j];
        }
    }

    int characterX, characterY;
    cin >> characterX >> characterY;

    int itemX, itemY;
    cin >> itemX >> itemY;

    int answer = solution(rectangle, characterX, characterY, itemX, itemY);

    cout << answer << '\n';

    return 0;
}