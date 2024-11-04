#include <iostream>
#include <cmath>
#include <climits>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer((int)targets.size(), 0);
    
    for (int i = 0; i < (int)targets.size(); i++)
    {
        for (int j = 0; j < (int)targets[i].length(); j++)
        {
            int cache = INT_MAX;
            for (int k = 0; k < (int)keymap.size(); k++)
            {
                auto iter = keymap[k].find_first_of(targets[i][j]);
                if (iter == string::npos)
                {
                    continue;
                }
                
                cache = min(cache, (int)iter + 1);
            }

            if (cache == INT_MAX)
            {
                cache = 0;
            }

            answer[i] += cache;
        }
    }

    for (int i = 0; i < (int)answer.size(); i++)
    {
        if (answer[i] == 0)
        {
            answer[i] = -1;
        }
    }
    
    return answer;
}

int main()
{
    int n;
    cin >> n;

    vector<string> keymap(n);
    for (int i = 0; i < n; i++)
    {
        cin >> keymap[i];
    }

    cin >> n;

    vector<string> targets(n);
    for (int i = 0; i < n; i++)
    {
        cin >> targets[i];
    }

    vector<int> answer = solution(keymap, targets);

    for (int i = 0; i < (int)answer.size(); i++)
    {
        cout << answer[i] << ' ';
    }
}