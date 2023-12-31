#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

priority_queue<int> map[100001];
int visited[100001];
int lv;

void dfs(int n) {
    visited[n] = lv;
    while (!map[n].empty()) {
        int nd = map[n].top();
        map[n].pop();

        if (visited[nd] == 0) {
            lv++;
            dfs(nd);
        }
    }
}

int main() {
    int n, m, r;
    cin >> n >> m >> r;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        map[a].push(b);
        map[b].push(a);
    }

    lv = 1;
    dfs(r);

    for (int i = 1; i <= n; i++) {
        cout << visited[i] << '\n';
    }
}