#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <utility>
#include <functional>

#define FAST_IO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

bool compare(const pair<int, int>& lhs, const pair<int, int>& rhs)
{
    return lhs.second < rhs.second;
}

int main()
{
    FAST_IO;

    int t;
    cin >> t;

    for (int ti = 1; ti <= t; ti++)
    {
        int n;
        cin >> n;

        unordered_map<int, vector<pair<int, int>>> ump;
        for (int i = 0; i < n; i++)
        {
            int a, b, c;
            cin >> a >> b >> c;

            ump[a].push_back({ b,c });
        }
        
        int answer = 0;
        for (auto it = ump.begin(); it != ump.end(); it++)
        {
            sort(it->second.begin(), it->second.end(), compare);

            int size = (int)it->second.size();
            vector<pair<int, int>> cache;
            cache.reserve(size);
            cache.push_back(it->second[0]);

            for (int i = 1; i < size; i++)
            {
                int b = it->second[i].first;
                int e = cache.back().second;
                if (b >= e)
                {
                    cache.push_back(it->second[i]);
                }
            }

            answer += (int)cache.size();
        }

        cout << "Scenario #" << ti << ":\n";
        cout << answer << "\n\n";
    }

    return 0;
}