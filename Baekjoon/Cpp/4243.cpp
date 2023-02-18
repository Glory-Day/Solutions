#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

typedef long long ll;

int main() {
    int t;
    cin >> t;

    ll cache[101][101][2];
    vector<ll> arr;
    while (t--) {
        int n, m;
        cin >> n >> m;

        memset(cache, -1, sizeof(cache));
        arr.clear();
        arr.resize(n + 1);

        for (int i = 2; i <= n; i++) {
            cin >> arr[i];
            arr[i] += arr[i - 1];
        }

        function<ll(int, int, int)> dfs = [&](int l, int r, int chk) {
            ll& tmp = cache[l][r][chk];
            if (tmp != -1) {
                return tmp;
            }

            if (l == 1 && r == n) {
                return tmp = 0;
            }

            tmp = 1e18;
            ll nd = chk ? r : l;
            ll nnd = n - r + l - 1;
            if (1 < l) {
                tmp = min(tmp, dfs(l - 1, r, 0) + nnd * (arr[nd] - arr[l - 1]));
            }
            
            if (r < n) {
                tmp = min(tmp, dfs(l, r + 1, 1) + nnd * (arr[r + 1] - arr[nd]));
            }

            return tmp;
        };

        cout << min(dfs(m, m, 0), dfs(m, m, 1)) << '\n';
    }
}