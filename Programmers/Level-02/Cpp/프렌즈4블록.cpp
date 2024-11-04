#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    
    vector<vector<bool>> caches(m, vector<bool>(n, false));
    while (true)
    {
        bool flag = false;
        for (int i = 0; i < m - 1; i++)
        {
            for (int j = 0; j < n - 1; j++)
            {
                if (board[i][j] == board[i + 1][j] && 
                    board[i][j] == board[i][j + 1] && 
                    board[i][j] == board[i + 1][j + 1] && 
                    board[i][j] != ' ')
                {
                    caches[i][j] = caches[i + 1][j] = caches[i][j + 1] = caches[i + 1][j + 1] = true;
                    flag = true;
                }
            }
        }
        
        if (flag == false)
        {
            break;
        }
        
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (caches[i][j] == true)
                {
                    board[i][j] = ' ';
                    caches[i][j] = false;
                    
                    answer++;
                }
            }
        }
        
        while (true)
        {
            int count = 0;
            for (int i = m - 2; i >= 0; i--)
            {
                for (int j = 0; j < n; j++)
                {
                    if (board[i][j] != ' ' && board[i + 1][j] == ' ')
                    {
                        swap(board[i][j], board[i + 1][j]);
                        
                        count++;
                    }
                }
            }
                        
            if (0 == count)
            {
                break;
            }
        }
    }
    
    return answer;
}

int main()
{
    int m, n;
    cin >> m >> n;

    vector<string> board(m);
    for (int i = 0; i < m; i++)
    {
        cin >> board[i];
    }

    int answer = solution(m, n, board);

    cout << answer;
}