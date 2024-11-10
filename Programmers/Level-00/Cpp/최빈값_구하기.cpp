#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>

using namespace std;

int solution(vector<int> array) {
    int answer = -1;
    
    if (array.empty() == false)
    {
        map<int, int> mp;
        for (int i = 0; i < (int)array.size(); i++)
        {
            mp[array[i]]++;
        }

        vector<pair<int, int>> caches(mp.begin(), mp.end());

        sort(caches.begin(), caches.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second > b.second;
        });
        
        answer = caches.front().first;
        
        int size = (int)caches.size();
        if (1 < size && caches[0].second == caches[1].second)
        {
            answer = -1;
        }
    }
    
    return answer;
}

int main()
{
    int n;
    cin >> n;

    vector<int> array(n);
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }

    int answer = solution(array);

    cout << answer;

    return 0;
}