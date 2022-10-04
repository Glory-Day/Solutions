#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

int n, k;
ll cache1[16][3];
ll cache2[51];
ll map[35001][101];

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

ll dfs(int a, int b) {
    if (a == (1 << n) - 1) return b == 0;
    if (map[a][b] != -1) return map[a][b];

    map[a][b] = 0;
    for (int i = 0; i < n; i++) {
        if (a & (1 << i)) continue;

        int m = (cache2[cache1[i][1]] * b + cache1[i][2]) % k;
        map[a][b] += dfs(a | (1 << i), m);
    }

    return map[a][b];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cache1[0][0] = cache2[0] = 1;
    string bt[16];

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> bt[i];
        cache1[i + 1][0] = cache1[i][0] * (i + 1);
    }

    cin >> k;

    for (int i = 0; i < n; i++) {
        cache1[i][1] = bt[i].size();

        for (auto& j: bt[i]) {
            cache1[i][2] = (10 * cache1[i][2] + (j - '0')) % k;
        }
    }

    for (int i = 1; i <= 50; i++) {
        cache2[i] = (cache2[i - 1] * 10) % k;
    }

    fill(map[0], map[35000], -1);

    ll a = dfs(0, 0);
    ll b = gcd(a, cache1[n][0]);

    cout << a / b << "/" << cache1[n][0] / b;
}