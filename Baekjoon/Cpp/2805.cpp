#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

int main() {
    ll n, k;
    cin >> n >> k;

    ll mx = 0;
    vector<ll> v;
    for (int i = 0; i < n; i++) {
        ll input;
        cin >> input;
        v.push_back(input);

        mx = max(mx, input);
    }

    ll mid = 0;
    ll b = 1, e = mx;
    ll answer = 0;
    while (b <= e) {
       mid = (b + e) / 2;

       ll sum = 0;
       for (ll& i: v) {
           sum += ((i - mid <= 0) ? 0 : i - mid);
       }

       if (sum >= k) {
           if (answer < mid) {
               answer = mid;
           }
           b = mid + 1;
       }
       else e = mid - 1;
    }

    cout << answer;
}