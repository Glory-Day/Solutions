#include <iostream>
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <utility>

using namespace std;

const pair<int, int> directions[4] = { { -1,0 },{ 1,0 },{ 0,-1 },{ 0,1 } };

const bool check(const vector<vector<int>>& maps, const int y, const int x)
{
    return 0 <= y && y < (int)maps.size() && 0 <= x && x < (int)maps[y].size();
}

int dfs(vector<vector<int>>& maps, const int y, const int x, const int n)
{    
    maps[y][x] = n;
    
    int sum = 0;
    for (const auto& d: directions)
    {
        int ny = y + d.first;
        int nx = x + d.second;
        if (check(maps, ny, nx) && maps[ny][nx] == 1)
        {
            sum += dfs(maps, ny, nx, n);
        }
    }
    
    return sum + 1;
}

int solution(vector<vector<int>> land) {
    int answer = 0;
    
    int index = 2;
    map<int, int> mp;
    for (int i = 0; i < (int)land.size(); i++)
    {
        for (int j = 0; j < (int)land[i].size(); j++)
        {
            if (check(land, i, j) && land[i][j] == 1)
            {
                mp[index] = dfs(land, i, j, index);
                
                index++;
            }
        }
    }
    
    
    for (int i = 0; i < (int)land[0].size(); i++)
    {
        set<int> caches;
        for (int j = 0; j < (int)land.size(); j++)
        {
            if (land[j][i] != 0)
            {
                caches.insert(land[j][i]);
            }
        }
        
        int sum = 0;
        for (auto iter = caches.begin(); iter != caches.end(); iter++)
        {
            sum += (*mp.find(*iter)).second;
        }
        
        answer = max(answer, sum);
    }
    
    return answer;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> land(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> land[i][j];
        }
    }

    int answer = solution(land);

    cout << answer;

    return 0;
}