#include <iostream>
#include <cmath>
#include <climits>
#include <vector>
#include <utility>

#define FAST_IO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

inline int get_manhattan_distance(const pair<int, int>& lhs, const pair<int, int>& rhs)
{
    return abs(lhs.first - rhs.first) + abs(lhs.second - rhs.second);
}

int main()
{
    FAST_IO;

    int n;
    cin >> n;

    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
    }

    int cache = 0;
    for (int i = 0; i < n - 1; i++)
    {
        cache += get_manhattan_distance(v[i], v[i + 1]);
    }

    int answer = cache;
    for (int i = 1; i < n - 2; i++)
    {
        int a = get_manhattan_distance(v[i - 1], v[i]) + get_manhattan_distance(v[i], v[i + 1]);
        int b = get_manhattan_distance(v[i - 1], v[i + 1]);

        answer = min(answer, cache - a + b);
    }

    cout << answer;

    return 0;
}