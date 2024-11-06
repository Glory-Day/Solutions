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

vector<string> solution(string my_string) {
    vector<string> answer;
    
    answer = split(my_string, ' ');
    
    return answer;
}

int main()
{
    string my_string;
    cin >> my_string;

    vector<string> answer = solution(my_string);
    
    for (int i = 0; i < (int)answer.size(); i++)
    {
        cout << answer[i] << '\n';
    }

    return 0;
}