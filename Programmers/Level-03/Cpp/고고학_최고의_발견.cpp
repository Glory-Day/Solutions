#include <iostream>
#include <cmath>
#include <vector>
#include <utility>
#include <functional>

using namespace std;

int solution(vector<vector<int>> clockHands)
{
    int answer = 0;

    int size = (int)clockHands.size();
    int cache = 1e9;

    vector<int> rows(size);

    auto rotate = [&](vector<vector<int>>& board, int row, int column, int count)
    {
        pair<int, int> directions[5] = { { -1,0 },{ 1,0 },{ 0,-1 },{ 0,1 },{ 0,0 } };

        for (const auto& direction: directions)
        {
            int a = row + direction.first;
            int b = column + direction.second;

            if (0 <= a && a < size && 0 <= b && b < size)
            {
                board[a][b] = (board[a][b] + count) % 4;
            }
        }
    };

    function<void(int)> dfs = [&](int column)
    {
        if (column == size)
        {
            vector<vector<int>> board = clockHands;
            vector<vector<int>> rotated(size, vector<int>(size, 0));

            for (int i = 0; i < size; i++)
            {
                rotated[0][i] = rows[i];
                
                rotate(board, 0, i, rows[i]);
            }

            for (int i = 1; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    int count = (4 - board[i - 1][j]) % 4;
                    rotated[i][j] = count;

                    rotate(board, i, j, count);
                }
            }

            bool valid = true;
            for (int i = 0; i < size; i++)
            {
                if (board[size - 1][i])
                {
                    valid = false;

                    break;
                }
            }

            if (valid)
            {
                int rotation = 0;
                for (int i = 0; i < size; i++)
                {
                    for (int j = 0; j < size; j++)
                    {
                        rotation += rotated[i][j];
                    }
                }

                cache = min(cache, rotation);
            }

            return;
        }

        for (int i = 0; i < 4; i++)
        {
            rows[column] = i;
            
            dfs(column + 1);
        }
    };

    dfs(0);

    answer = cache;

    return answer;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> clockHands(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> clockHands[i][j];
        }
    }

    int answer = solution(clockHands);

    cout << answer << '\n';

    return 0;
}