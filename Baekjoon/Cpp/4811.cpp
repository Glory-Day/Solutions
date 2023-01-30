#include <iostream>

using namespace std;

using ll = long long;

ll cache[31][31];

int main() {
    for (int i = 0; i <= 30; i++) {
        for (int j = 0; j <= 30; j++) {
            if (i > j) {
                continue;
            }

            if (i == 0) {
                cache[i][j] = 1;
            }
            else {
                cache[i][j] = cache[i - 1][j] + cache[i][j - 1];
            }
        }
    }

    while (true) {
        int n;
        cin >> n;

        if (n == 0) {
            break;
        }

        cout << cache[n][n] << '\n';
    }
}