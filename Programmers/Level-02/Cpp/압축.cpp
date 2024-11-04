#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    
    map<string, int> mp;
    for (char i = 'A'; i <= 'Z'; i++)
    {
        mp[string(1, i)] = (i - 'A') + 1;
    }
    
    while (msg.empty() == false)
    {
        string cache;
        for (int i = 1; i <= (int)msg.length(); i++)
        {
            cache = msg.substr(0, i);
            if (mp.find(cache) == mp.end())
            {
                break;
            }
        }
        
        if (mp.find(cache) == mp.end())
        {
            mp[cache] = (int)mp.size() + 1;
            cache.pop_back();
        }

        msg.erase(0, (int)cache.length());
        
        answer.push_back(mp[cache]);
    }
    
    return answer;
}

int main()
{
    string msg;
    cin >> msg;

    vector<int> answer = solution(msg);

    for (int i = 0; i < (int)answer.size(); i++)
    {
        cout << answer[i] << ' ';
    }
}