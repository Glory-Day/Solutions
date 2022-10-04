#include <iostream>

using namespace std;

int map[201];

int find(int nd) {
    if (map[nd] == nd) return nd;
    return map[nd] = find(map[nd]);
}

void join(int a, int b) {
    a = find(a), b = find(b);

    if (a < b) map[a] = b;
    else map[b] = a;
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        map[i] = i;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int input;
            cin >> input;
            if (input == 1) join(i, j);
        }
    }

    int p;
    cin >> p;
    p = find(p);
    for (int i = 1; i < m; i++) {
        int nd;
        cin >> nd;

        if (p != find(nd)) {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";
}