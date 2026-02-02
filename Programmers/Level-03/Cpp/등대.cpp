#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int solution(int n, vector<vector<int>> lighthouse)
{
    int answer;

    vector<int> graph[100001];
    for (auto& edge : lighthouse)
    {
        int a = edge[0];
        int b = edge[1];

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int cache[100001][2];
    bool visited[100001];
    
    function<void(int)> dfs = [&](int node)
    {
        cache[node][0] = 0;
        cache[node][1] = 1;
        visited[node] = true;
        
        for (int child : graph[node])
        {
            if (visited[child] == false)
            {
                dfs(child);

                cache[node][0] += cache[child][1];
                cache[node][1] += min(cache[child][0], cache[child][1]);
            }
        }
    };

    dfs(1);
    
    answer = min(cache[1][0], cache[1][1]);

    return answer;
}

int main()
{
    int n;
    cin >> n;
    
    vector<vector<int>> lighthouse(n - 1, vector<int>(2));
    for (int i = 0; i < n - 1; i++)
    {
        cin >> lighthouse[i][0] >> lighthouse[i][1];
    }
    
    int answer = solution(n, lighthouse);

    cout << answer << endl;
    
    return 0;
}