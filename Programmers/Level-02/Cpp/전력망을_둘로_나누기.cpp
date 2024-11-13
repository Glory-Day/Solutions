#include <iostream>
#include <cmath>
#include <climits>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> wires) {
    int answer = INT_MAX;
    
    vector<vector<int>> matrix(n + 1);
    for (int i = 0; i < (int)wires.size(); i++)
    {
        matrix[wires[i][0]].push_back(wires[i][1]);
        matrix[wires[i][1]].push_back(wires[i][0]);
    }
    
    queue<int> q;
    for (int i = 0; i < (int)wires.size(); i++)
    {
        int count = 1;
        int a = wires[i][0];
        int b = wires[i][1];
        
        vector<bool> visited(n + 1, false);
        visited[a] = true;
        visited[b] = true;
        
        q.push(a);
        
        while (q.empty() == false)
        {
            int p = q.front();
            q.pop();
            
            for (int j = 0; j < (int)matrix[p].size(); j++)
            {
                int nd = matrix[p][j];
                
                if (visited[nd])
                {
                    continue;
                }
                
                visited[nd] = true;
                count++;
                
                q.push(nd);
            }
        }
        
        answer = min(answer, abs(count * 2 - n));
    }
    
    return answer;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> wires(n - 1, vector<int>(2));
    for (int i = 0; i < n - 1; i++)
    {
        cin >> wires[i][0] >> wires[i][1];
    }

    int answer = solution(n, wires);

    cout << answer;

    return 0;
}