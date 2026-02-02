#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int solution(int n, vector<vector<int>> edge) 
{
    vector<vector<int>> graph(n + 1);
    
    for (auto& e : edge) 
    {
        int u = e[0];
        int v = e[1];
        
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    queue<int> q;
    vector<int> distances(n + 1, -1);
    
    q.push(1);
    distances[1] = 0;
    
    while (q.empty() == false) 
    {
        int u = q.front();
        q.pop();
        
        for (int node : graph[u]) 
        {
            if (distances[node] == -1) 
            {
                distances[node] = distances[u] + 1;
                q.push(node);
            }
        }
    }
    
    int cache = 0;
    for (int i = 1; i <= n; i++) 
    {
        if (distances[i] > cache) 
        {
            cache = distances[i];
        }
    }
    
    int answer = 0;
    for (int i = 1; i <= n; i++) 
    {
        if (distances[i] == cache) 
        {
            answer++;
        }
    }
    
    return answer;
}

int main()
{
    int n;
    cin >> n;

    int m;
    cin >> m;

    vector<vector<int>> edge(m, vector<int>(2));
    for (int i = 0; i < m; i++)
    {
        cin >> edge[i][0] >> edge[i][1];
    }

    int answer = solution(n, edge);

    cout << answer;

    return 0;
}