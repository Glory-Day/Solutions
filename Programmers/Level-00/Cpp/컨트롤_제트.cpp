#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> split(const string& s, const char token)
{
    vector<string> result;
    
    string cache = "";
    for (int i = 0; i < (int)s.length(); i++)
    {
        if (s[i] == token)
        {
            result.push_back(cache);
            cache.clear();
            
            continue;
        }
        
        cache.push_back(s[i]);
    }
    
    if (cache.empty() == false)
    {
        result.push_back(cache);
    }
    
    return result;
}

const int to_integer(const string& s)
{
    int result = 0;
    
    int flag = (s.front() == '-' ? 1 : 0);
    for (int i = (int)s.length() - 1, j = 1; i >= flag; i--, j *= 10)
    {
        result += (s[i] - '0') * j;
    }
    
    if (0 < flag)
    {
        result *= -1;
    }
    
    return result;
}

int solution(string s) {
    int answer = 0;
    
    vector<string> caches = split(s, ' ');
    for (int i = 0; i < (int)caches.size(); i++)
    {
        if (caches[i] == "Z")
        {
            answer -= to_integer(caches[i - 1]);
            
            continue;
        }
        
        answer += to_integer(caches[i]);
    }
    
    return answer;
}

int main()
{
    string s;
    cin >> s;

    int answer = solution(s);

    cout << answer;

    return 0;
}