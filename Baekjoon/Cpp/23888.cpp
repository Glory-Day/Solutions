#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
	if (b == 0) {
        return a;
    }

	return gcd(b, a % b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll b, d;
    cin >> b >> d;

    int n;
    cin >> n;

    while (n--) {
        int q, l, r;
        cin >> q >> l >> r;

        if (q == 1) {
            ll a1 = r * (2ll * b + (r - 1ll) * d) / 2ll;
			ll a2 = (l - 1ll) * (2ll * b + (l - 2ll) * d) / 2ll;

			cout << a1 - a2 << "\n";
        }
        else if (q == 2) {
            if (l == r) cout << b + (l - 1) * d << "\n";
            else cout << gcd(b, d) << "\n";
        }
    }
}