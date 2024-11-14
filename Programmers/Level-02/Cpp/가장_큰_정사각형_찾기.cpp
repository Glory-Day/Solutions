#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = 0;
    
    int matrix[1001][1001];
    int row = (int)board.size();
    int column = (int)board[0].size();
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            matrix[i + 1][j + 1] = board[i][j];
        }
    }
    
    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= column; j++)
        {
            if (matrix[i][j] != 0)
            {
                matrix[i][j] = min(min(matrix[i - 1][j], matrix[i - 1][j - 1]), matrix[i][j - 1]) + 1;
            }
        }
    }
    
    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= column; j++)
        {
            answer = max(answer, matrix[i][j]);
        }
    }
    
    answer *= answer;
    
    return answer;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> board(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }
    }

    int answer = solution(board);

    cout << answer;

    return 0;
}