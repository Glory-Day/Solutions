#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
    int a, b, c, n;
    cin >> a >> b >> c >> n;

    vector<ll> arr;
    ll mx = 1e18;
    for (ll i = 1; i < mx; i *= a) {
        for (ll j = i; j < mx; j *= b) {
            for (ll k = j; k < mx; k *= c) {
                if (k > 0) {
                    arr.push_back(k);
                }
            }
        }
    }

    sort(arr.begin(), arr.end());

    cout << arr[n];
}