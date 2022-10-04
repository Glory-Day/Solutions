#include <iostream>

#define MOD 1000000000

using namespace std;

typedef long long ll;

ll cache[101][10];

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= 9; i++) {
        cache[1][i] = 1;
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= 9; j++) {
            if (j == 0) {
                cache[i][j] = (cache[i][j] + cache[i - 1][j + 1]) % MOD;
            }
            else if (j == 9) {
                cache[i][j] = (cache[i][j] + cache[i - 1][j - 1]) % MOD;
            }
            else {
                cache[i][j] = (cache[i - 1][j - 1] + cache[i - 1][j + 1]) % MOD;
            }
        }
    }

    ll sum = 0;
    for (int i = 0; i <= 9; i++) {
        sum += cache[n][i];
    }

    cout << sum % MOD;
}