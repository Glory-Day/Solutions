#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>

using namespace std;

vector<string> split(const string& s)
{
    vector<string> result;
    
    string cache = "";
    for (int i = 0; i < (int)s.length(); i++)
    {
        if (s[i] == ' ')
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

string solution(string letter) {
    string answer = "";
    
    map<string, string> mp = { 
        { ".-","a" },{ "-...","b" },{ "-.-.","c" },{ "-..","d" },{ ".","e" },{ "..-.","f" },
        { "--.","g" },{ "....","h" },{ "..","i" },{ ".---","j" },{ "-.-","k" },{ ".-..","l" },
        { "--","m" },{ "-.","n" },{ "---","o" },{ ".--.","p" },{ "--.-","q" },{ ".-.","r" },
        { "...","s" },{ "-","t" },{ "..-","u" },{ "...-","v" },{ ".--","w" },{ "-..-","x" },
        { "-.--","y" },{ "--..","z" }
    };
    
    vector<string> caches = split(letter);
    for (int i = 0; i < (int)caches.size(); i++)
    {
        answer += mp[caches[i]];
    }
    
    return answer;
}

int main()
{
    string letter;
    cin >> letter;

    string answer = solution(letter);

    cout << answer;

    return 0;
}