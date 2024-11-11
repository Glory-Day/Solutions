#include <iostream>
#include <string>
#include <vector>

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

vector<string> split(const string& s, const char token)
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

const int to_second(const string& s)
{
    vector<string> caches = split(s, ':');
    
    int a = to_integer(caches[0]);
    int b = to_integer(caches[1]);
    
    return a * 60 + b;
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    
    int cache = to_second("00:10");
    
    int l = to_second(video_len);
    int p = to_second(pos);
    int s = to_second(op_start);
    int e = to_second(op_end);
    for (int i = 0; i < (int)commands.size(); i++)
    {
        if (s <= p && p <= e)
        {
            p = e;
        }
        
        if (commands[i] == "next")
        {
            p += cache;
        }
        else
        {
            p -= cache;
        }
        
        if (p < 0)
        {
            p = 0;
        }
        
        if (l < p)
        {
            p = l;
        }
    }
    
    if (s <= p && p <= e)
    {
        p = e;
    }
    
    int h = p / 60;
    int m = p % 60;
    
    answer += (h < 10 ? "0" + to_string(h) + ":" : to_string(h) + ":");
    answer += (m < 10 ? "0" + to_string(m) : to_string(m));
    
    return answer;
}

int main()
{
    string video_len, pos, op_start, op_end;
    cin >> video_len >> pos >> op_start >> op_end;

    int n;
    cin >> n;

    vector<string> commands(n);
    for (int i = 0; i < n; i++)
    {
        cin >> commands[i];
    }

    string answer = solution(video_len, pos, op_start, op_end, commands);

    cout << answer;

    return 0;
}