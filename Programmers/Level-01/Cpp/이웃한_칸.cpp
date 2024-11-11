#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;
    
    int n = (int)board.size();
    if (0 <= h - 1 && h - 1 < n && 0 <= w && w < n)
    {
        answer += (int)(board[h][w] == board[h - 1][w]);
    }

    if (0 <= h + 1 && h + 1 < n && 0 <= w && w < n)
    {
        answer += (int)(board[h][w] == board[h + 1][w]);
    }

    if (0 <= h && h < n && 0 <= w - 1 && w - 1 < n)
    {
        answer += (int)(board[h][w] == board[h][w - 1]);
    }

    if (0 <= h && h < n && 0 <= w + 1 && w + 1 < n)
    {
        answer += (int)(board[h][w] == board[h][w + 1]);
    }
    
    return answer;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<string>> board(n, vector<string>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }
    }

    int h, w;
    cin >> h >> w;

    int answer = solution(board, h, w);

    cout << answer;

    return 0;
}