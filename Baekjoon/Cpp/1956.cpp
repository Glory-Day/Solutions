#include <iostream>
#include <climits>
#include <algorithm>

#define MAX 1e9

using namespace std;

int map[401][401];

void fw(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                if (map[j][k] > map[j][i] + map[i][k]) {
                    map[j][k] = map[j][i] + map[i][k];
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
            map[i][j] = MAX;
        }
    }

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        map[a][b] = min(map[a][b], c);
    }

    fw(n);

    int mn = MAX;
    for (int i = 1; i <= n; i++) {
        mn = min(map[i][i], mn);
    }

    if (mn == MAX) cout << -1 << '\n';
    else cout << mn << '\n';
}