#include <iostream>

using namespace std;

int cache[11][11];

int f(int n, int k) {
    if (cache[n][k]) return cache[n][k];
    else if (k > n) return 0;
    else if (k == 0 || k == n) return 1;
    return cache[n][k] = f(n - 1, k - 1) + f(n - 1, k);
}

int main() {
    int n, k;
    cin >> n >> k;

    cache[0][0] = cache[1][0] = cache[0][1] = 1;

    cout << f(n, k);
}