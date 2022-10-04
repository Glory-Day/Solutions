#include <iostream>

using namespace std;

int map[1000001];

int find(int nd) {
    if (map[nd] == nd) return nd;
    return map[nd] = find(map[nd]);
}

void join(int a, int b) {
    a = find(a), b = find(b);
    if (a > b) map[a] = b;
    else if (a < b) map[b] = a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i <= n; i++) {
        map[i] = i;
    }

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        if (a == 0) join(b, c);
        else {
            if (find(b) == find(c)) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}