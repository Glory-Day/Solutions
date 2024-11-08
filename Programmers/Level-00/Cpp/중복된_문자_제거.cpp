#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>

using namespace std;

string solution(string my_string) {
    string answer = "";
    
    map<char, int> mp;
    for (int i = 0; i < (int)my_string.length(); i++)
    {
        if (mp.find(my_string[i]) == mp.end())
        {
            mp[my_string[i]] = i;
        }
    }
    
    vector<pair<int, char>> caches;
    for (auto iter = mp.begin(); iter != mp.end(); iter++)
    {
        caches.push_back({ (*iter).second,(*iter).first });
    }
    
    sort(caches.begin(), caches.end());
    
    for (int i = 0; i < (int)caches.size(); i++)
    {
        answer.push_back(caches[i].second);
    }
    
    return answer;
}

int main()
{
    string my_string;
    cin >> my_string;

    string answer = solution(my_string);

    cout << answer;

    return 0;
}