#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <utility>

using namespace std;

const pair<int, int> directions[4] = { { -1,0 },{ 1,0 },{ 0,-1 },{ 0,1 } };

const int bfs(vector<string> maps, const pair<int, int> b, const pair<int, int> e)
{
    int result = -1;
    
    queue<tuple<int, int, int>> q;
    q.push(make_tuple(b.first, b.second, 0));
    
    maps[b.first][b.second] = 'X';
    
    while (q.empty() == false)
    {
        auto nd = q.front();
        q.pop();
        
        if (get<0>(nd) == e.first && get<1>(nd) == e.second)
        {
            result = get<2>(nd);
        }
        
        for (const auto& d: directions)
        {
            int y = get<0>(nd) + d.first;
            int x = get<1>(nd) + d.second;
            
            if (0 <= y && y < (int)maps.size() && 
                0 <= x && x < (int)maps[0].length() && 
                maps[y][x] != 'X')
            {
                maps[y][x] = 'X';
                
                q.push(make_tuple(y, x, get<2>(nd) + 1));
            }
        }
    }
    
    return result;
}

int solution(vector<string> maps) {
    int answer = 0;
    
    pair<int, int> s, l, e;
    for (int i = 0; i < (int)maps.size(); i++)
    {
        for (int j = 0; j < (int)maps[i].length(); j++)
        {
            switch (maps[i][j])
            {
                case 'S': s = { i,j }; break;
                case 'L': l = { i,j }; break;
                case 'E': e = { i,j }; break;
            }
        }
    }
    
    int a = bfs(vector<string>(maps.begin(), maps.end()), s, l);
    int b = bfs(vector<string>(maps.begin(), maps.end()), l, e);
    answer = a + b;
    if (a < 0 || b < 0)
    {
        answer = -1;
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

    int answer = solution(maps);

    cout << answer;

    return 0;
}