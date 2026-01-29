#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <functional>

#define FAST_IO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

inline int get_distance(const pair<int, int>& lhs, const pair<int, int>& rhs)
{
    int dx = lhs.first - rhs.first;
    int dy = lhs.second - rhs.second;

    return dx * dx + dy * dy;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
    }

    vector<pair<int, int>> w(m);
    for (int i = 0; i < m; i++)
    {
        cin >> w[i].first >> w[i].second;
    }

    pair<int, int> cache = { 0,0 };
    auto compare = [&](const pair<int, int>& lhs, const pair<int, int>& rhs)
    {
        int a = get_distance(cache, lhs);
        int b = get_distance(cache, rhs);

        return a < b;
    };

    int answer = 0;
    for (int i = 0; i < m; i++)
    {
        sort(v.begin(), v.end(), compare);

        auto tmp = v.back();
        v.pop_back();

        answer += get_distance(cache, tmp);
        cache = tmp;

        v.push_back(w[i]);
    }

    cout << answer;

    return 0;
}