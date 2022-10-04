#include <iostream>
#include <vector>

using namespace std;

vector<int> map[20001];
int visited[20001];

bool dfs(int nd, int lv) {
    bool check = true;
    int color = (lv % 2 != 1) ? 2 : 1;

    if (!visited[nd]) {
        visited[nd] = color;

        for (int& i: map[nd]) {
            if (!dfs(i, lv + 1)) {
                check = false;
                break;
            }
        }
    }
    else {
        if (visited[nd] != color) return false;
    }

    return check;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        for (int i = 1; i <= n; i++) {
            map[i].clear();
        }

        fill(visited, visited + 20000, 0);

        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            map[a].push_back(b);
            map[b].push_back(a);
        }

        bool check = true;
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                if (!dfs(i, 1)) {
                    check = false;
                    break;
                }
            }
        }

        if (check) cout << "YES\n";
        else cout << "NO\n";
    }
}