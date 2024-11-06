#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

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

vector<string> solution(string myString) {
    vector<string> answer;
    
    answer = split(myString, 'x');
    
    sort(answer.begin(), answer.end());
    
    return answer;
}

int main()
{
    string myString;
    cin >> myString;

    vector<string> answer = solution(myString);
    
    for (int i = 0; i < (int)answer.size(); i++)
    {
        cout << answer[i] << '\n';
    }

    return 0;
}