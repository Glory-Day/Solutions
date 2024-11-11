#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    
    string cache = "";
    for (char i = 'a'; i <= 'z'; i++)
    {
        auto iter = skip.find(i);
        if (iter == string::npos)
        {
            cache.push_back(i);
        }
    }
    
    int n = (int)cache.length();
    for (int i = 0; i < (int)s.length(); i++)
    {
        auto iter = (cache.find(s[i]) + index) % n;
        
        answer.push_back(cache[iter]);
    }
    
    return answer;
}

int main()
{
    string s, skip;
    cin >> s >> skip;

    int index;
    cin >> index;

    string answer = solution(s, skip, index);

    cout << answer;

    return 0;
}