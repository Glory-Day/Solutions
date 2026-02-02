#include <iostream>
#include <limits>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination)
{
    vector<int> answer;

    const int INF = numeric_limits<int>::max();

    vector<vector<int>> graph(n + 1);
    for (const auto& road: roads)
    {
        int a = road[0];
        int b = road[1];

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int> distances(n + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    distances[destination] = 0;
    pq.push({ 0,destination });

    while (pq.empty() == false)
    {
        auto node = pq.top();
        pq.pop();

        if (node.first > distances[node.second])
        {
            continue;
        }

        for (int i: graph[node.second])
        {
            int nd = node.first + 1;
            if (nd < distances[i])
            {
                distances[i] = nd;

                pq.push({ nd,i });
            }
        }
    }

    for (int source: sources)
    {
        answer.push_back(distances[source] == INF ? -1 : distances[source]);
    }

    return answer;
}

int main()
{
    int n;
    cin >> n;

    int m;
    cin >> m;

    vector<vector<int>> roads(m, vector<int>(2));
    for (int i = 0; i < m; i++)
    {
        cin >> roads[i][0] >> roads[i][1];
    }

    cin >> m;

    vector<int> sources(m);
    for (int i = 0; i < m; i++)
    {
        cin >> sources[i];
    }
    
    int destination;
    cin >> destination;

    vector<int> answer = solution(n, roads, sources, destination);
    
    for (int i = 0; i < (int)answer.size(); i++)
    {
        cout << answer[i] << ' ';
    }
    
    return 0;
}