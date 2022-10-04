#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

int map[101][101];

void fw(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                if (map[j][i] != INT_MAX && map[i][k] != INT_MAX) {
                    map[j][k] = min(map[j][k], map[j][i] + map[i][k]);
                }
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            map[i][j] = INT_MAX;
        }
    }

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (map[a][b] != INT_MAX) {
            map[a][b] = min(map[a][b], c);
        }
        else {
            map[a][b] = c;
        }
    }

    fw(n);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j || map[i][j] == INT_MAX) {
                cout << 0 << ' ';
            }
            else {
                cout << map[i][j] << ' ';
            }
        }
        cout << '\n';
    }
}