#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays)
{
    vector<int> answer;

    map<string, int> temp;
    map<string, vector<pair<int, int>>> mp;
    
    int size = (int)genres.size();
    for (int i = 0; i < size; i++)
    {
        temp[genres[i]] += plays[i];
        mp[genres[i]].push_back({plays[i], i});
    }
    
    vector<pair<int, string>> caches;
    for (auto& i : temp)
    {
        caches.push_back({ i.second,i.first });
    }

    sort(caches.begin(), caches.end(), greater<pair<int, string>>());
    
    auto compare = [&](const pair<int, int>& lhs, const pair<int, int>& rhs)
    {
        return lhs.first != rhs.first ? lhs.first > rhs.first : lhs.second < rhs.second;
    };

    for (auto& cache : caches)
    {
        string key = cache.second;
        vector<pair<int, int>>& songs = mp[key];
        
        sort(songs.begin(), songs.end(), compare);
        
        int count = min(2, (int)songs.size());
        for (int i = 0; i < count; i++)
        {
            answer.push_back(songs[i].second);
        }
    }
    
    return answer;
}

int main()
{
    int n;
    cin >> n;

    vector<string> genres(n);
    for (int i = 0; i < n; i++)
    {
        cin >> genres[i];
    }

    vector<int> plays(n);
    for (int i = 0; i < n; i++)
    {
        cin >> plays[i];
    }

    vector<int> answer = solution(genres, plays);

    for (auto& i: answer)
    {
        cout << i << ' ';
    }

    return 0;
}