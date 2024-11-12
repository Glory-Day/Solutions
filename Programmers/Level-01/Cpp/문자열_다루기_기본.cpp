#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    bool answer = true;

    if ((int)s.length() == 4 || (int)s.length() == 6)
    {
        for (auto i: s) {
            if('0' <= i && '9' >= i)
            {
                continue;
            }

            answer = false;

            break;
        }
    }
    else
    {
        answer = false;
    }
    
    return answer;
}

int main()
{
    string s;
    cin >> s;

    bool answer = solution(s);

    cout << answer;

    return 0;
}