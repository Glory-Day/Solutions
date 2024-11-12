#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    
    for (auto i: s)
    {
        if (i >= 'a' && i <= 'z')
        {
            int temp = (i + n);
            if (temp > 'z')
            {
                answer += temp - 26;
            }
            else
            {
                answer += temp;
            }
            
        }
        else if (i >= 'A' && i <= 'Z') {
            int temp = (i + n);
            if (temp > 'Z')
            {
                answer += temp - 26;
            }
            else
            {
                answer += temp;
            }
        }
        else
        {
            answer += i;
        }
    }

    return answer;
}

int main()
{
    string s;
    cin >> s;

    int n;
    cin >> n;

    string answer = solution(s, n);

    cout << answer;

    return 0;
}