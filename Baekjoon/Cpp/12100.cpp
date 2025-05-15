#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
#include <utility>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
	
    int n;
    cin >> n;
	
    int mx = 0;
    vector<vector<int>> map(20, vector<int>(20));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
            
            mx = max(mx, map[i][j]);
        }
    }
	
    auto up = [&](vector<vector<int>> map)
    {
        for (int i = 0; i < n; i++)
        {
            queue<int> q;
            for (int j = 0; j < n; j++)
            {
                if (map[j][i] != 0)
                {
                    q.push(map[j][i]);
                    map[j][i] = 0;
                }
            }
			
            int idx = 0;
            vector<bool> visited(n, true);
            while (!q.empty())
            {
                if (idx > 0)
                {
                    if (map[idx - 1][i] == q.front() && visited[idx - 1])
                    {
                        map[idx - 1][i] += q.front();
                        mx = max(mx, map[idx - 1][i]);
                        visited[idx - 1] = false;
                        q.pop();
                        
                        continue;
                    }
                }
				
                map[idx][i] = q.front();
                q.pop();
                idx++;
            }
        }
		
        return map;
    };
	
    auto down = [&](vector<vector<int>> map)
    {
        for (int i = 0; i < n; i++)
        {
            queue<int> q;
            for (int j = n - 1; j >= 0; j--)
            {
                if (map[j][i] != 0)
                {
                    q.push(map[j][i]);
                    map[j][i] = 0;
                }
            }
			
            int idx = n - 1;
            vector<bool> visited(n, true);
            while (!q.empty())
            {
                if (idx < n - 1)
                {
                    if (map[idx + 1][i] == q.front() && visited[idx + 1])
                    {
                        map[idx + 1][i] += q.front();
                        mx = max(mx, map[idx + 1][i]);
                        visited[idx + 1] = false;
                        q.pop();
		                
						continue;
                    }
                }
				
                map[idx][i] = q.front();
                q.pop();
                idx--;
            }
        }
		
        return map;
    };
    
    auto left = [&](vector<vector<int>> map)
    {
        for (int i = 0; i < n; i++)
        {
            queue<int> q;
            for (int j = 0; j < n; j++)
            {
                if (map[i][j] != 0)
                {
                    q.push(map[i][j]);
                    map[i][j] = 0;
                }
            }

            int idx = 0;
            vector<bool> visited(n, true);
            while (!q.empty())
            {
                if (idx > 0)
                {
                    if (map[i][idx - 1] == q.front() && visited[idx - 1])
                    {
                        map[i][idx - 1] += q.front();
                        mx = max(mx, map[i][idx - 1]);
                        visited[idx - 1] = false;
                        q.pop();
	                    
	                    continue;
                    }
                }
				
                map[i][idx] = q.front();
                q.pop();
                idx++;
            }
        }
		
        return map;
    };
	
    auto right = [&](vector<vector<int>> map)
    {
        for (int i = 0; i < n; i++)
        {
            queue<int> q;
            for (int j = n - 1; j >= 0; j--)
            {
                if (map[i][j] != 0)
                {
                    q.push(map[i][j]);
                    map[i][j] = 0;
                }
            }
			
            int idx = n - 1;
            vector<bool> visited(n, true);
            while (!q.empty())
            {
                if (idx < n - 1)
                {
                    if (map[i][idx + 1] == q.front() && visited[idx + 1])
                    {
                        map[i][idx + 1] += q.front();
                        mx = max(mx, map[i][idx + 1]);
                        visited[idx + 1] = false;
                        q.pop();
	                    
						continue;
                    }
                }
				
                map[i][idx] = q.front();
                q.pop();
                idx--;
            }
        }
		
        return map;
    };
	
    function<void(vector<vector<int>>, int)> dfs = [&](vector<vector<int>> map, int lv)
    {
        if (lv == 5)
        {
            return;
        }
		
        dfs(up(map), lv + 1);
        dfs(down(map), lv + 1);
        dfs(left(map), lv + 1);
        dfs(right(map), lv + 1);
    };
	
    dfs(map, 0);
	
    int answer = mx;
    cout << answer;
	
	return 0;
}