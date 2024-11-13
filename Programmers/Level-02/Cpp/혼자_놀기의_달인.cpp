#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const bool compare(const vector<int>& a, const vector<int>& b)
{
    return a.size() > b.size();
}

int solution(vector<int> cards) {
    int answer = 0;
    
    vector<bool> visited((int)cards.size(), false);
    
    int count = 0;
    vector<vector<int>> caches;
    for (int i = 0; i < (int)cards.size(); i++)
    {
        int nd = cards[i] - 1;
        vector<int> cache;
        while (visited[nd] == false)
        {
            cache.push_back(nd);
            visited[nd] = true;
            
            nd = cards[nd] - 1;
        }
        
        caches.push_back(cache);
    }
    
    sort(caches.begin(), caches.end(), compare);
    
    if (1 < (int)caches.size())
    {
        answer = (int)(caches[0].size() * caches[1].size());
    }
    
    return answer;
}

int main()
{
    int n;
    cin >> n;

    vector<int> cards(n);
    for (int i = 0; i < n; i++)
    {
        cin >> cards[i];
    }

    int answer = solution(cards);

    cout << answer;

    return 0;
}