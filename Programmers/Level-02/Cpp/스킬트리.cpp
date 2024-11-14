#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    vector<int> cache(26, -1);
    for (int i = 0; i < skill.size(); i++) {
        cache[skill[i] - 'A'] = i;
    }
    
    for (auto& i: skill_trees) {
        int idx = 0;
        bool isValid = true;
        for (auto& j: i) {
            if (cache[j - 'A'] == -1) {
                continue;
            }
            
            if (cache[j - 'A'] != idx) {
                isValid = false;
                break;
            }
            else {
                idx++;
            }
        }
        
        if (isValid) {
            answer++;
        }
    }
    
    return answer;
}

int main()
{
    string skill;
    cin >> skill;

    int n;
    cin >> n;

    vector<string> skill_trees(n);
    for (int i = 0; i < n; i++)
    {
        cin >> skill_trees[i];
    }

    int answer = solution(skill, skill_trees);

    cout << answer;

    return 0;
}