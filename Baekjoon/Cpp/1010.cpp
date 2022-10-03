#include <iostream>

using namespace std;

typedef long long ll;

ll cache[31][31];

ll f(int n, int k) {
    if (cache[n][k]) return cache[n][k];
    else if (k > n) return 0;
    else if (k == 0 || k == n) return 1;
    return cache[n][k] = f(n - 1, k - 1) + f(n - 1, k);
}

int main() {
    int n;
    cin >> n;

    cache[0][0] = cache[1][0] = cache[0][1] = 1;

    for (int i = 0; i < n; i++) {
        int m, k;
        cin >> m >> k;
        cout << f(m, k) << '\n';
    }
}