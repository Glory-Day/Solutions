#include <iostream>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

bool solution(string s)
{
    bool answer = true;

    int pCount = 0; int yCount = 0;
    pCount += count(s.begin(), s.end(), 'p');
    pCount += count(s.begin(), s.end(), 'P');
    yCount += count(s.begin(), s.end(), 'y');
    yCount += count(s.begin(), s.end(), 'Y');
    
    if (pCount != yCount)
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