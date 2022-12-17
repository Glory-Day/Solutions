#include <iostream>

using namespace std;
using ll = long long;

ll cache[55];

ll f(ll x) {
    ll y = x & 1, a = 0;
    for (int i = 54; i > 0; i--) {
        a = (1LL << i);
        if (x & a) {
            y += cache[i - 1] + (x - a + 1);
            x -= a;
        }
    }

    return y;
}

int main() {
    ll a, b;
    cin >> a >> b;

    cache[0] = 1;
    for (int i = 1; i < 55; i++) {
        cache[i] = cache[i - 1] * 2 + (1LL << i);
    }

    cout << f(b) - f(a - 1);
}