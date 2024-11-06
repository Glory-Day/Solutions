#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>

using namespace std;

vector<int> solution(vector<int> arr, int k) {
    vector<int> answer;
    
    map<int, int> mp;
    for (int i = 0; i < (int)arr.size(); i++)
    {
        if (mp.find(arr[i]) == mp.end())
        {
            mp[arr[i]] = i;
        }
    }
    
    vector<pair<int, int>> caches;
    for (auto iter = mp.begin(); iter != mp.end(); iter++)
    {
        int a = (*iter).first;
        int b = (*iter).second;
        caches.push_back({ b,a });
    }
    
    sort(caches.begin(), caches.end());
    
    for (int i = 0; i < k && i < (int)caches.size(); i++)
    {
        answer.push_back(caches[i].second);
    }
    
    for (int i = 0; i < k - (int)caches.size(); i++)
    {
        answer.push_back(-1);
    }
    
    return answer;
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    vector<int> answer = solution(arr, k);
    
    for (int i = 0; i < (int)answer.size(); i++)
    {
        cout << answer[i] << ' ';
    }

    return 0;
}