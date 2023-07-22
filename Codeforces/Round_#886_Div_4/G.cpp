#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pr;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<pr> v;
        for (int i = 0; i < n; i++) {
            ll a, b;
            cin >> a >> b;
            v.push_back({ a,b });
        }

        int answer = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (abs(v[i].first - v[j].first) == 0 || abs(v[i].second - v[j].second) == 0 || abs(v[i].first - v[j].first) == abs(v[i].second - v[j].second)) {
                    answer += 2;
                }
            }
        }

        cout << answer << '\n';
    }

    return 0;
}