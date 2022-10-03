#include <iostream>

#define MOD 10007

using namespace std;

typedef long long ll;

ll cache[1001][1001];

ll f(int n, int k) {
    if (cache[n][k]) return cache[n][k];
    else if (k > n) return 0;
    else if (k == 0 || k == n) return 1;
    return cache[n][k] = (f(n - 1, k - 1) + f(n - 1, k)) % MOD;
}

int main() {
    int n, k;
    cin >> n >> k;

    cache[0][0] = cache[1][0] = cache[0][1] = 1;

    cout << f(n, k);
}