#include <iostream>
#include <map>

using namespace std;

using ll = long long;

const ll dfs(map<ll, ll>& mp, const ll n, const ll p, const ll q)
{
    if (n == 0)
    {
        return mp[0];
    }

    if (mp.find(n) != mp.end())
    {
        return mp[n];
    }

    return mp[n] = dfs(mp, n / p, p, q) + dfs(mp, n / q, p, q);
}

int main()
{
    ll n, p, q;
    cin >> n >> p >> q;

    map<ll, ll> mp;
    mp[0] = 1;

    dfs(mp, n, p, q);

    cout << mp[n];

    return 0;
}