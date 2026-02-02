#include <iostream>
#include <cmath>
#include <vector>
#include <utility>
#include <algorithm>
#include <functional>

using namespace std;

using Point = pair<int, int>;
using Shape = vector<pair<int, int>>;

int solution(vector<vector<int>> game_board, vector<vector<int>> table)
{
    int answer = 0;

    Point directions[4] = { { -1,0 },{ 1,0 },{ 0,-1 },{ 0,1 } };

    int size = (int)game_board.size();
    vector<vector<int>> visited(size, vector<int>(size, 0));

    auto check = [&](int x, int y)
    {
        return 0 <= x && x < (int)game_board.size() && 0 <= y && y < (int)game_board[0].size();
    };

    auto extract = [&](const vector<vector<int>>& board, int x, int y, int target)
    {
        Shape result;

        vector<Point> queue;
        queue.push_back({ x,y });
        visited[x][y] = 1;

        while (queue.empty() == false)
        {
            auto current = queue.back();
            queue.pop_back();

            result.push_back(current);

            for (const auto& direction: directions)
            {
                int nx = current.first + direction.first;
                int ny = current.second + direction.second;

                if (check(nx, ny) && visited[nx][ny] == 0 && board[nx][ny] == target)
                {
                    visited[nx][ny] = 1;

                    queue.push_back({ nx,ny });
                }
            }
        }

        return result;
    };

    auto normalize = [&](Shape shape)
    {
        if (shape.empty())
        {
            return shape;
        }

        int x = shape[0].first;
        int y = shape[0].second;
        for (const auto& point: shape)
        {
            x = min(x, point.first);
            y = min(y, point.second);
        }

        Shape result;
        for (const auto& point: shape)
        {
            result.push_back({ point.first - x,point.second - y });
        }

        sort(result.begin(), result.end());

        return result;
    };

    vector<Shape> blanks;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (game_board[i][j] == 0 && visited[i][j] == 0)
            {
                auto blank = extract(game_board, i, j, 0);
                blanks.push_back(normalize(blank));
            }
        }
    }

    visited.assign(size, vector<int>(size, 0));

    vector<Shape> pieces;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (table[i][j] == 1 && visited[i][j] == 0)
            {
                auto piece = extract(table, i, j, 1);
                pieces.push_back(normalize(piece));
            }
        }
    }

    size = (int)pieces.size();
    vector<int> cache(size, 0);

    auto rotate = [&](Shape shape)
    {
        Shape result;

        for (const auto& point: shape)
        {
            result.push_back({ point.second,-point.first });
        }

        return normalize(result);
    };

    auto get_all_rotated_shapes = [&](Shape shape)
    {
        vector<Shape> result;

        Shape current = normalize(shape);
        for (int i = 0; i < 4; i++)
        {
            result.push_back(current);
            current = rotate(current);
        }

        return result;
    };

    auto match = [&](const Shape& blank)
    {
        for (int i = 0; i < size; i++)
        {
            if (cache[i])
            {
                continue;
            }

            vector<Shape> rotations = get_all_rotated_shapes(pieces[i]);
            for (const auto& rotated: rotations)
            {
                if (blank == rotated)
                {
                    return i;
                }
            }
        }

        return -1;
    };
    
    for (const auto& blank: blanks)
    {
        int index = match(blank);
        if (index != -1)
        {
            cache[index] = 1;

            answer += (int)blank.size();
        }
    }

    return answer;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> game_board(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> game_board[i][j];
        }
    }

    vector<vector<int>> table(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> table[i][j];
        }
    }

    int answer = solution(game_board, table);

    cout << answer << '\n';

    return 0;
}