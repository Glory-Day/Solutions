#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> split(string s, const char token)
{
    vector<string> result;
    
    string cache = "";
    for (int i = 0; i < (int)s.length(); i++)
    {
        if (s[i] == token && cache.empty() == false)
        {
            result.push_back(cache);
            cache.clear();
            
            continue;
        }
        else if (s[i] != token)
        {
            cache.push_back(s[i]);
        }
    }
    
    if (cache.empty() == false)
    {
        result.push_back(cache);
    }
    
    return result;
}

vector<string> split(vector<string> s, const char token)
{
    vector<string> result;
    
    for (int i = 0; i < (int)s.size(); i++)
    {
        vector<string> caches = split(s[i], token);
        for (int j = 0; j < (int)caches.size(); j++)
        {
            result.push_back(caches[j]);
        }
    }
    
    return result;
}

vector<string> solution(string myStr) {
    vector<string> answer;
    
    answer = split(split(split(myStr, 'a'), 'b'), 'c');
    if (answer.empty())
    {
        answer.push_back("EMPTY");
    }
    
    return answer;
}

int main()
{
    string myStr;
    cin >> myStr;

    vector<string> answer = solution(myStr);
    
    for (int i = 0; i < (int)answer.size(); i++)
    {
        cout << answer[i] << '\n';
    }

    return 0;
}