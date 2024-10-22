#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

using pii = pair<int, int>;

struct point
{
    int y, x, c;
};

const pii directions[4] = { { -1,0 },{ 1,0 },{ 0,-1 },{ 0,1 } };

bool visited[101][101];

const bool check(const int y, const int x, const int row, const int column)
{
    return 0 <= x && x < column && 0 <= y && y < row;
}

int bfs(const vector<string>& board, const pii& r, const pii& g)
{
    int result = -1;
    int row = (int)board.size();
    int column = (int)board[0].size();
    
    visited[r.first][r.second] = true;
    
    queue<point> q;
    q.push({ r.first,r.second,0 });
    
    while (q.empty() == false)
    {
        auto p = q.front();
        q.pop();
        
        if (p.y == g.first && p.x == g.second)
        {
            result = p.c;
        }
        
        for (const auto& d: directions)
        {
            int ny = p.y;
            int nx = p.x;
            
            while (check(ny + d.first, nx + d.second, row, column) && 
                   (board[ny + d.first][nx + d.second] == '.' ||
                    board[ny + d.first][nx + d.second] == 'G' ||
                    board[ny + d.first][nx + d.second] == 'R'))
            {
                ny += d.first;
                nx += d.second;
            }
            
            if (visited[ny][nx] == false)
            {
                visited[ny][nx] = true;
                
                q.push({ ny,nx,p.c + 1 });
            }
        }
    }
    
    return result;
}

int solution(vector<string> board) {
    int answer = 0;
    
    pii r, g;
    for (int i = 0; i < (int)board.size(); i++)
    {
        for (int j = 0; j < (int)board[0].size(); j++)
        {
            if (board[i][j] == 'R')
            {
                r.first = i;
                r.second = j;
            }
            else if (board[i][j] == 'G')
            {
                g.first = i;
                g.second = j;
            }
        }
    }
    
    answer = bfs(board, r, g);
    
    return answer;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<string> board(n);
    for (int i = 0; i < n; i++)
    {
        cin >> board[i];
    }

    cout << solution(board);
}