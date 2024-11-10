#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <functional>

using namespace std;

vector<int> solution(vector<int> emergency) {
    vector<int> answer((int)emergency.size());
    
    vector<pair<int, int>> caches;
    for (int i = 0; i < (int)emergency.size(); i++)
    {
        caches.push_back({ emergency[i],i });
    }
    
    sort(caches.begin(), caches.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.first > b.first;
    });
    
    for (int i = 1; i <= (int)caches.size(); i++)
    {
        answer[caches[i - 1].second] = i;
    }
    
    return answer;
}

int main()
{
    int n;
    cin >> n;

    vector<int> emergency(n);
    for (int i = 0; i < n; i++)
    {
        cin >> emergency[i];
    }

    vector<int> answer = solution(emergency);

    for (int i = 0; i < (int)answer.size(); i++)
    {
        cout << answer[i] << ' ';
    }

    return 0;
}