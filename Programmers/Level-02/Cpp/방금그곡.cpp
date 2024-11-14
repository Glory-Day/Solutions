#include <iostream>
#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

vector<string> split(const string& s)
{
    vector<string> result;
    
    string cache = "";
    for (int i = 0; i < (int)s.length(); i++)
    {
        if (s[i] == ',')
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

const int to_second(const string& s)
{
    int h = (s[0] - '0') * 10 + (s[1] - '0');
    int m = (s[3] - '0') * 10 + (s[4] - '0');
    
    return h * 60 + m;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "";
    
    string s = "";
    for (int i = 0; i < (int)m.size() - 1; i++)
    {
        s.push_back(m[i]);
        
        if (m[i + 1] == '#')
        {
            s.push_back('#');
            i++;
        }
        else
        {
            s.push_back('0');
        }
    }
    
    if (m.back() != '#')
    {
        s.push_back(m.back());
        s.push_back('0');
    }
    
    cout << s << '\n';
    
    vector<tuple<int, int, string>> results;
    for (int i = 0; i < (int)musicinfos.size(); i++)
    {
        vector<string> caches = split(musicinfos[i]);
        string code = "";
        
        int n = to_second(caches[1]) - to_second(caches[0]);
        int l = (int)caches[3].length();
        for (int j = 0; j < n; j++)
        {
            code.push_back(caches[3][j % l]);
            
            if (caches[3][(j + 1) % l] == '#')
            {
                code.push_back('#');
                n++;
                j++;
            }
            else
            {
                code.push_back('0');
            }
        }
        
        cout << code << '\n';
        
        if (code.find(s) != string::npos)
        {
            results.push_back(make_tuple(n, i, caches[2]));
        }
    }
    
    if (results.empty())
    {
        answer = "(None)";
    }
    else
    {
        sort(results.begin(), results.end(), 
             [](const tuple<int, int, string>& a, const tuple<int, int, string>& b) {
                 if (get<0>(a) == get<0>(b))
                 {
                     return get<1>(a) < get<1>(b);
                 }
                 
                 return get<0>(a) > get<0>(b);
             });
        
        answer = get<2>(results.front());
    }
    
    return answer;
}

int main()
{
    string m;
    cin >> m;

    int n;
    cin >> n;

    vector<string> musicinfos(n);
    for (int i = 0; i < n; i++)
    {
        cin >> musicinfos[i];
    }

    string answer = solution(m, musicinfos);

    cout << answer;

    return 0;
}