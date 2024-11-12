#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";

    if(s.length() % 2 == 0)
    {
        answer += s[(int)s.length() / 2 - 1];
        answer += s[(int)s.length() / 2];
    }
    else
    {
        answer = s[(int)s.length() / 2];
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