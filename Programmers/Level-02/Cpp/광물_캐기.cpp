#include <iostream>
#include <cmath>
#include <climits>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

unordered_map<string, int> ump;
const int caches[3][3] = { { 1,1,1 },{ 5,1,1 },{ 25,5,1 } };

void dfs(vector<int>& picks, vector<string>& minerals, int& answer, const int sum, const int index)
{
    if (index == (int)minerals.size() || (picks[0] + picks[1] + picks[2] == 0))
    {
        answer = min(answer, sum);
        
        return;
    }
    
    for (int i = 0; i < 3; i++)
    {
        if (picks[i] != 0)
        {
            picks[i]--;
            
            int j;
            int cache = sum;
            for (j = index; j < index + 5 && j < (int)minerals.size(); j++)
            {
                cache += caches[i][ump[minerals[j]]];
            }
            
            dfs(picks, minerals, answer, cache, j);
            
            picks[i]++;
        }
    }
}

int solution(vector<int> picks, vector<string> minerals) {
    int answer = INT_MAX;
    
    ump.insert({ "diamond",0 });
    ump.insert({ "iron",1 });
    ump.insert({ "stone",2 });
    
    dfs(picks, minerals, answer, 0, 0);
    
    return answer;
}

int main()
{
    vector<int> picks(3);
    cin >> picks[0] >> picks[1] >> picks[2];

    int n;
    cin >> n;

    vector<string> minerals(n);
    for (int i = 0; i < n; i++)
    {
        cin >> minerals[i];
    }

    int answer = solution(picks, minerals);

    cout << answer;

    return 0;
}