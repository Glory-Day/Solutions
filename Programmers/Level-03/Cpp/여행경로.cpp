#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

vector<string> solution(vector<vector<string>> tickets)
{
    vector<string> answer;

    int size = (int)tickets.size();

    sort(tickets.begin(), tickets.end());
    
    vector<bool> visited(size, false);
    vector<string> path;
    
    function<bool(string, int)> dfs = [&](string current, int depth)
    {
        path.push_back(current);
    
        if (depth == size)
        {
            return true;
        }

        for (int i = 0; i < size; i++)
        {
            if (visited[i] == false && tickets[i][0] == current)
            {
                visited[i] = true;
                if (dfs(tickets[i][1], depth + 1))
                {
                    return true;
                }
                visited[i] = false;
            }
        }
        
        path.pop_back();

        return false;
    };

    dfs("ICN", 0);

    answer = path;
    
    return answer;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<string>> tickets(n, vector<string>(2));
    for (int i = 0; i < n; i++)
    {
        cin >> tickets[i][0] >> tickets[i][1];
    }

    vector<string> answer = solution(tickets);

    for (auto& i: answer)
    {
        cout << i << ' ';
    }

    return 0;
}