#include <iostream>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results)
{
    int answer = 0;

    vector<vector<int>> graph(n + 1, vector<int>(n + 1, 0));
    
    for (const auto& result : results)
    {
        int a = result[0];
        int b = result[1];
        
        graph[a][b] = 1;
    }
    
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (graph[i][k] && graph[k][j])
                {
                    graph[i][j] = 1;
                }
            }
        }
    }
    
    for (int i = 1; i <= n; i++)
    {
        int count = 0;
        for (int j = 1; j <= n; j++)
        {
            if (graph[i][j] || graph[j][i])
            {
                count++;
            }
        }
        
        if (count == n - 1)
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

    vector<vector<int>> results(n, vector<int>(2));
    for (int i = 0; i < n; i++)
    {
        cin >> results[i][0] >> results[i][1];
    }

    int answer = solution(n, results);

    cout << answer << '\n';

    return 0;
}