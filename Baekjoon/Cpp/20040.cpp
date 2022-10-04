#include <iostream>

using namespace std;

int map[500001];

int find(int nd) {
    if (map[nd] == nd) return nd;
    return map[nd] = find(map[nd]);
}

bool unite(int a, int b) {
    a = find(a), b = find(b);

    if (a == b) return true;

    map[a] = b;
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        map[i] = i;
    }

    int answer = 0;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;

        if (unite(a, b)) {
            answer = i;
            break;
        }
    }

    cout << answer;
}