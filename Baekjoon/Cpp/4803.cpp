#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int map[501];
unordered_set<int> tree;

int find(int nd) {
    if (nd == map[nd]) return nd;
    return find(map[nd]);
}

bool join(int a, int b) {
    a = find(a), b = find(b);
    if (a == b) {
        map[b] = a;
        map[a] = 0;
        return false;
    }
    else if (a < b) map[b] = a;
    else map[a] = b;

    return true;
}

int main() {
    for (int t = 1; true; t++) {
        int n, m;
        cin >> n >> m;

        if (n == 0 && m == 0) break;

        tree.clear();
        for (int i = 1; i <= n ; i++) map[i] = i;

        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            join(a, b);
        }

        for (int i = 1; i <= n; i++) {
            int nd = find(i);
            if (nd) tree.insert(nd);
        }

        cout << "Case " << t << ": ";
        if (tree.empty()) cout << "No trees.\n";
        else if (tree.size() == 1) cout << "There is one tree.\n";
        else cout << "A forest of " << tree.size() << " trees.\n";
    }
}