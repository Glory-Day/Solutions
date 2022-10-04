#include <iostream>

using namespace std;

#define MOD 1000000000

int cache[201][201];

int main() {
    int n, m;
    cin >> n >> m;

    cache[0][0] = 1;

    for (int i = 1; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            for (int k = 0; k <= j; k++) {
                cache[i][j] = (cache[i][j] + cache[i - 1][j - k]) % MOD;
            }
        }
    }

    cout << cache[m][n];
}