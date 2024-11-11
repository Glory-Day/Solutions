#include <iostream>
#include <string>
#include <vector>
#include <map>
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

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    
    map<string, int> a;
    map<string, map<string, int>> b;
    for (int i = 0; i < (int)gifts.size(); i++)
    {
        vector<string> caches = split(gifts[i], ' ');
        
        a[caches[0]]++;
        a[caches[1]]--;
        
        b[caches[0]][caches[1]]++;
    }
    
    int n = (int)friends.size();
    vector<int> caches(n, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (b[friends[i]][friends[j]] == b[friends[j]][friends[i]])
            {
                if (a[friends[i]] < a[friends[j]])
                {
                    caches[j]++;
                }
                else if (a[friends[i]] > a[friends[j]])
                {
                    caches[i]++;
                }
            }
            else
            {
                if (b[friends[i]][friends[j]] < b[friends[j]][friends[i]])
                {
                    caches[j]++;
                }
                else if (b[friends[i]][friends[j]] > b[friends[j]][friends[i]])
                {
                    caches[i]++;
                }
            }
        }
    }
    
    answer = *max_element(caches.begin(), caches.end());
    
    return answer;
}

int main()
{
    int n;
    cin >> n;

    vector<string> friends(n);
    for (int i = 0; i < n; i++)
    {
        cin >> friends[i];
    }

    int m;
    cin >> m;

    vector<string> gifts(m);
    for (int i = 0; i < m; i++)
    {
        cin >> gifts[i];
    }

    int answer = solution(friends, gifts);

    cout << answer;

    return 0;
}