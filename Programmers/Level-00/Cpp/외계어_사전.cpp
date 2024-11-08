#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<string> spell, vector<string> dic) {
    int answer = 2;
    
    for (int i = 0; i < (int)dic.size(); i++)
    {
        bool check = true;
        for (int j = 0; j < (int)spell.size(); j++)
        {
            if (dic[i].find(spell[j]) == string::npos)
            {
                check = false;
            }
        }
        
        if (check)
        {
            answer = 1;
        }
    }
    
    return answer;
}

int main()
{
    int n;
    cin >> n;

    vector<string> spell(n);
    for (int i = 0; i < n; i++)
    {
        cin >> spell[i];
    }

    int m;
    cin >> m;

    vector<string> dic(m);
    for (int i = 0; i < m; i++)
    {
        cin >> dic[i];
    }

    int answer = solution(spell, dic);

    cout << answer;

    return 0;
}