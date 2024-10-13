#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

const bool compare(const pii& a, const pii& b)
{
    if (a.first == b.first)
    {
        return a.second > b.second;
    }

    return a.first < b.first;
}

int main()
{
    int n;
    cin >> n;

    vector<pii> v(n * 2);
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;

        v[i * 2] = { a,1 };
        v[i * 2 + 1] = { b,-1 };
    }

    sort(v.begin(), v.end(), compare);

    
    int l = 0;
    int cache = 0;
    ll answer = 0;
    for (const auto& i: v)
    {
        if (l == 0 && l + i.second == 1)
        {
            cache = i.first;
        }
        else if (l == 1 && l + i.second == 0)
        {
            answer += i.first - cache;
        }

        l += i.second;
    }

    cout << answer;

    return 0;
}