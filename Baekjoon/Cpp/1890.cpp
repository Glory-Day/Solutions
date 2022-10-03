#include <iostream>

using namespace std;

typedef long long ll;

int map[101][101];
ll cache[101][101];

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }

    cache[0][0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!cache[i][j] || (i == n - 1 && j == n - 1)) {
                continue;
            }

            int d = map[i][j] + i;
            int r = map[i][j] + j;

            if (d < n) cache[d][j] += cache[i][j];
            if (r < n) cache[i][r] += cache[i][j];
        }
    }

    cout << cache[n - 1][n - 1];
}