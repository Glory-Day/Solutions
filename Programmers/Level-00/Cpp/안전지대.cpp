#include <iostream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

int solution(vector<vector<int>> board) {
    int answer = 0;
    
    vector<pair<int, int>> directions = {
        { -1,-1 },{ 0,-1 },{ 1,-1 },{ -1,0 },{ 0,0 },{ 1,0 },{ -1,1 },{ 0,1 },{ 1,1 }
    };
    
    int n = (int)board.size();
    vector<vector<int>> caches(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == 0)
            {
                continue;
            }
            
            for (int k = 0; k < 9; k++)
            {
                int y = i + directions[k].first;
                int x = j + directions[k].second;
                if (0 <= y && y < n && 0 <= x && x < n)
                {
                    caches[y][x]++;
                }
            }
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (caches[i][j] == 0)
            {
                answer++;
            }
        }
    }
    
    return answer;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> board(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
        }
    }

    int answer = solution(board);

    cout << answer;

    return 0;
}