#include <iostream>
#include <climits>
#include <cmath>
#include <vector>

using namespace std;

using ll = long long;

int main()
{
    ll n, k;
    cin >> n >> k;

    vector<ll> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    ll b = 1;
    ll e = 2e9;
    ll answer = LLONG_MAX;
    while (b <= e)
    {
        ll m = (b + e) / 2;
        
        ll sum = m * (m + 1) / 2;
        for (int i = 0; i < n - 1; i++)
        {
            ll d = min(m, v[i + 1] - v[i]);
            ll sa = m * (m + 1) / 2;
            ll sb = (m - d) * (m - d + 1) / 2;
            sum += sa - sb;
        }

        if (k <= sum)
        {
            e = m - 1;
            answer = min(answer, m);
        }
        else
        {
            b = m + 1;
        }
    }

    cout << answer;

    return 0;
}