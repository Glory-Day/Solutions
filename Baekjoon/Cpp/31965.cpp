#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;

ll caches[200001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<ll> v(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }

    for (int i = 1; i <= n; i++)
    {
        caches[i] = caches[i - 1] + v[i];
    }

    auto f = [&v](const int i, const int j, const int k)
    {
        ll l = (ll)(k - i + 1) * v[k] - (caches[k] - caches[i - 1]);
        ll r = (caches[j] - caches[k - 1]) - (ll)(j - k + 1) * v[k];

        return l + r;
    };

    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;

        int b = lower_bound(v.begin() + 1, v.end(), l) - v.begin();
        int e = upper_bound(v.begin() + 1, v.end(), r) - v.begin() - 1;

        ll answer;
        if (b < e)
        {
            ll mx = max(f(b, e, b), f(b, e, e));
            ll mn = f(b, e, (b + e) / 2);

            answer = mx - mn;
        }
        else
        {
            answer = 0LL;
        }

        cout << answer << '\n';
    }

    return 0;
}