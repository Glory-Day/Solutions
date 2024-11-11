#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

const int to_integer(const string& s)
{
    int result = 0;
    for (int i = (int)s.length() - 1, j = 1; i >= 0; i--, j *= 10)
    {
        result += (s[i] - '0') * j;
    }
    
    return result;
}

vector<string> split(const string& s, const char token = ' ')
{
    vector<string> result;
    
    string cache = "";
    for (int i = 0; i < (int)s.length(); i++)
    {
        if (s[i] == token)
        {
            if (cache.empty() == false)
            {
                result.push_back(cache);
                cache.clear();
            }
            
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

const int to_day(const string& s)
{
    vector<string> caches = split(s, '.');
    int y = to_integer(caches[0]) * 12 * 28;
    int m = to_integer(caches[1]) * 28;
    int d = to_integer(caches[2]);
    
    return y + m + d;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    
    int n = to_day(today);
    
    map<char, int> mp;
    for (int i = 0; i < (int)terms.size(); i++)
    {
        vector<string> caches = split(terms[i]);
        
        mp[caches[0][0]] = to_integer(caches[1]);
    }
    
    for (int i = 0; i < (int)privacies.size(); i++)
    {
        vector<string> caches = split(privacies[i]);
        
        int d = to_day(caches[0]) + mp[caches[1][0]] * 28;
        if (n >= d)
        {
            answer.push_back(i + 1);
        }
    }
    
    return answer;
}

int main()
{
    string today;
    cin >> today;

    int n;
    cin >> n;

    vector<string> terms(n);
    for (int i = 0; i < n; i++)
    {
        cin >> terms[i];
    }

    int m;
    cin >> m;

    vector<string> privacies(m);
    for (int i = 0; i < m; i++)
    {
        cin >> privacies[i];
    }

    vector<int> answer = solution(today, terms, privacies);

    for (int i = 0; i < (int)answer.size(); i++)
    {
        cout << answer[i] << ' ';
    }

    return 0;
}