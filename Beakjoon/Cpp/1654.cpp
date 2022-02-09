#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

typedef long long ll;

vector<ll> v;

ll s(ll l) {
    ll sum = 0;

    for (ll& i: v) {
        sum += (i / l);
    }

    return sum;
}

ll ps(ll b, ll e, ll k) {
    ll mid = 0, sum, answer = 0;

    while (b <= e) {
        mid = (b + e) / 2;
        sum = s(mid);

        if (sum >= k) {
            if (answer < mid) {
                answer = mid;
            }
            b = mid + 1;
        }
        else e = mid - 1;
    }

    return b - 1;
}



int main() {
    ll n, k;
    cin >> n >> k;

    ll mx = 0;
    for (int i = 0; i < n; i++) {
        ll input;
        cin >> input;
        v.push_back(input);

        mx = max(mx, input);
    }

    cout << ps(1, mx, k);
}