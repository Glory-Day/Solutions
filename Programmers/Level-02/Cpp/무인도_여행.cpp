#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

using pii = pair<int, int>;

const pii directions[4] = { { -1,0 },{ 1,0 },{ 0,-1 },{ 0,1 } };

const bool check(const int y, const int x, const int row, const int column)
{
    return 0 <= y && y < row && 0 <= x && x < column;
}

int bfs(vector<string>& maps, int y, int x)
{
    int result = (maps[y][x] - '0');
    int row = (int)maps.size();
    int column = (int)maps[0].size();
    
    maps[y][x] = 'X';
    
    queue<pii> q;
    q.push({ y,x });
    
    while (q.empty() == false)
    {
        auto p = q.front();
        q.pop();
        
        for (const auto& d: directions)
        {
            int ny = p.first + d.first;
            int nx = p.second + d.second;
            
            if (check(ny, nx, row, column) && maps[ny][nx] != 'X')
            {
                result += (maps[ny][nx] - '0');
                maps[ny][nx] = 'X';
                
                q.push({ ny,nx });
            }
        }
    }
    
    return result;
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    
    for (int i = 0; i < (int)maps.size(); i++)
    {
        for (int j = 0; j < (int)maps[0].size(); j++)
        {
            if (maps[i][j] != 'X')
            {
                answer.push_back(bfs(maps, i, j));
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    
    if (answer.empty())
    {
        answer.push_back(-1);
    }
    
    return answer;
}

int main()
{
    int n;
    cin >> n;

    vector<string> maps(n);
    for (int i = 0; i < n; i++)
    {
        cin >> maps[i];
    }

    vector<int> answer = solution(maps);

    for (int i = 0; i < (int)answer.size(); i++)
    {
        cout << answer[i] << ' ';
    }

    return 0;
}