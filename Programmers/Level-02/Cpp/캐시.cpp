#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    
    for (int i = 0; i < (int)cities.size(); i++)
    {
        for (int j = 0; j < (int)cities[i].length(); j++)
        {
            cities[i][j] = tolower(cities[i][j]);
        }
    }
    
    deque<string> caches;
    for (int i = 0; i < (int)cities.size(); i++)
    {
        auto iter = find(caches.begin(), caches.end(), cities[i]);
        if (iter == caches.end())
        {
            answer += 5;
            
            if (cacheSize > 0)
            {
                caches.push_back(cities[i]);
            }
            else 
            {
                continue;
            }
            
            if ((int)caches.size() > cacheSize)
            {
                caches.pop_front();
            }
        }
        else
        {
            string cache = *iter;
            caches.erase(iter);
            caches.push_back(cache);
            
            answer++;
        }
    }
    
    return answer;
}

int main()
{
    int cacheSize;
    cin >> cacheSize;

    int n;
    cin >> n;

    vector<string> cities(n);
    for (int i = 0; i < n; i++)
    {
        cin >> cities[i];
    }

    int answer = solution(cacheSize, cities);

    cout << answer;

    return 0;
}