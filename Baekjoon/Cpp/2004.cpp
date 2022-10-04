#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

ll f1(ll n) {
    ll cnt = 0;
    for (ll i = 2; i <= n; i*=2) {
        cnt += n / i;
    }
    return cnt;
}

ll f2(ll n) {
    ll cnt = 0;
    for (ll i = 5; i <= n; i*=5) {
        cnt += n / i;
    }
    return cnt;
}

int main() {
    ll n, m;
    cin >> n >> m;
    cout << min(f1(n) - (f1(m) + f1(n - m)), f2(n) - (f2(m) + f2(n - m)));
}