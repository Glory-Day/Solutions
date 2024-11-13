#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>

using namespace std;

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer(4, 0);
    
    map<int, pair<int, int>> mp;
    for (int i = 0; i < (int)edges.size(); i++)
    {
        mp[edges[i][0]].first++;
        mp[edges[i][1]].second++;
    }
    
    for (auto iter = mp.begin(); iter != mp.end(); iter++)
    {
        if ((*iter).second.first > 1 && (*iter).second.second == 0)
        {
            answer[0] = (*iter).first;
        }
        else if ((*iter).second.first == 0 && (*iter).second.second > 0)
        {
            answer[2]++;
        }
        else if ((*iter).second.first > 1 && (*iter).second.second > 1)
        {
            answer[3]++;
        }
    }
    
    answer[1] = (*mp.find(answer[0])).second.first - (answer[2] + answer[3]);
    
    return answer;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> edges(n, vector<int>(2));
    for (int i = 0; i < n; i++)
    {
        cin >> edges[i][0] >> edges[i][1];
    }

    vector<int> answer = solution(edges);

    for (int i = 0; i < (int)answer.size(); i++)
    {
        cout << answer[i] << ' ';
    }

    return 0;
}