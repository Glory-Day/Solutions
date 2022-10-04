#include <iostream>

using namespace std;

int cache[1025][1025];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int input;
            cin >> input;
            cache[i + 1][j + 1] = cache[i][j + 1] + cache[i + 1][j] - cache[i][j] + input;
        }
    }

    for (int i = 0; i < m; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << cache[c][d] - cache[a - 1][d] - cache[c][b - 1] + cache[a - 1][b - 1] << '\n';
    }
}