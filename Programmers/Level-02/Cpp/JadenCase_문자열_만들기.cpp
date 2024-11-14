#include <iostream>
#include <cctype>
#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    
    bool toggle = true;
    for (int i = 0; i < (int)s.length(); i++)
    {
        if (s[i] == ' ')
        {
            answer.push_back(s[i]);
            toggle = true;
        }
        else if (toggle)
        {
            answer.push_back(toupper(s[i]));
            toggle = false;
        }
        else
        {
            answer.push_back(tolower(s[i]));
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