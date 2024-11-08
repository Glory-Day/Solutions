#include <iostream>
#include <string>
#include <cctype>
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
    
    for (int i = (int)s.length() - 1, j = 1; i >= 0; i--, j *= 10)
    {
        result += (s[i] - '0') * j;
    }
    
    return result;
}

string solution(string polynomial) {
    string answer = "";
    
    int a = 0, b = 0;
    vector<string> caches = split(polynomial, ' ');
    for (int i = 0; i < (int)caches.size(); i++)
    {
        if (caches[i].back() == 'x')
        {
            caches[i].pop_back();
            
            if (caches[i].empty())
            {
                a++;
            }
            else
            {
                a += to_integer(caches[i]);
            }
        }
        else if (caches[i] != "+")
        {
            b += to_integer(caches[i]);
        }
    }
    
    if (a == 0 && b == 0)
    {
        answer += "0";
    }
    else if (a != 0 && b == 0)
    {
        answer += (a == 1 ? "x" : to_string(a) + "x");
    }
    else if (a == 0 && b != 0)
    {
        answer += to_string(b);
    }
    else if (a != 0 && b != 0)
    {
        answer += (a == 1 ? "x" : to_string(a) + "x");
        answer += " + ";
        answer += to_string(b);
    }
    
    return answer;
}

int main()
{
    string polynomial;
    cin >> polynomial;

    string answer = solution(polynomial);

    cout << answer;

    return 0;
}