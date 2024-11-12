#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

string solution(string s) {
    string answer = "";
    
    int index = 0;
    for (int i = 0; i < (int)s.length(); i++)
    {
        if (s[i] == ' ')
        {
            index = 0;
            
            answer += ' ';
        }
        else
        {
            if (index % 2 == 0)
            {
                answer += toupper(s[i]);
            }
            else
            {
                answer += tolower(s[i]);
            }

            index++;
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