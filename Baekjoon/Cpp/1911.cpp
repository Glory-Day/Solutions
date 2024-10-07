#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <utility>

using namespace std;

using pii = pair<int, int>;

int main()
{
    int n, l;
    cin >> n >> l;

    vector<pii> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
    }

    sort(v.begin(), v.end());

    int answer = 0;
    int cache = v.front().first;
    for (int i = 0; i < n; i++)
    {
        if (cache > v[i].second)
        {
            continue;
        }
        else if (cache < v[i].first)
        {
            cache = v[i].first;
        }

        int d = v[i].second - cache;
        int r = d % l ? 1 : 0;
        int count = d / l + r;
        cache += count * l;
        answer += count;
    }

    cout << answer;

    return 0;
}