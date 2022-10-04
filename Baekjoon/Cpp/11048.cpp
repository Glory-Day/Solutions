#include <iostream>
#include <algorithm>

using namespace std;

int map[1001][1001];
int cache[1001][1001];

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> map[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cache[i][j] = max(max(cache[i - 1][j], cache[i][j - 1]), cache[i - 1][j - 1]) + map[i][j];
        }
    }

    cout << cache[n][m];
}