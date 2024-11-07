#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    
    vector<int> caches(26, 0);
    for (int i = 0; i < (int)s.length(); i++)
    {
        caches[s[i] - 'a']++;
    }
    
    for (int i = 0; i < 26; i++)
    {
        if (caches[i] == 1)
        {
            answer.push_back(i + 'a');
        }
    }
    
    return answer;
}

int main()
{
    string s;
    cin >> s;

    string answer = solution(s);

    cout << answer;

    return 0;
}