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
    
    result.push_back(cache);
    
    return result;
}

vector<int> solution(string myString) {
    vector<int> answer;
    
    vector<string> caches = split(myString, 'x');
    for (int i = 0; i < (int)caches.size(); i++)
    {
        answer.push_back((int)caches[i].size());
    }
    
    return answer;
}

int main()
{
    string myString;
    cin >> myString;

    vector<int> answer = solution(myString);
    
    for (int i = 0; i < (int)answer.size(); i++)
    {
        cout << answer[i] << ' ';
    }

    return 0;
}