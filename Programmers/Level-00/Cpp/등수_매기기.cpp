#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>

using namespace std;

vector<int> solution(vector<vector<int>> score) {
    vector<int> answer((int)score.size());
    
    map<int, vector<int>> mp;
    for (int i = 0; i < (int)score.size(); i++)
    {
        mp[(score[i][0] + score[i][1])].push_back(i);
    }
    
    int index = 1;
    for (auto iter = mp.rbegin(); iter != mp.rend(); iter++)
    {
        for (int i = 0; i < (int)(*iter).second.size(); i++)
        {
            answer[(*iter).second[i]] = index;
        }
        
        index += (int)(*iter).second.size();
    }
    
    return answer;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> score(n, vector<int>(2));
    for (int i = 0; i < n; i++)
    {
        cin >> score[i][0] >> score[i][1];
    }

    vector<int> answer = solution(score);

    for (int i = 0; i < (int)answer.size(); i++)
    {
        cout << answer[i] << ' ';
    }

    return 0;
}