#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

priority_queue<int> map[100001];
int visited[100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m, r;
    cin >> n >> m >> r;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        map[a].push(b);
        map[b].push(a);
    }

    int lv = 1;
    queue<int> q;
    q.push(r);
    visited[r] = lv++;

    while (!q.empty()) {
        int nd = q.front();
        q.pop();

        while (!map[nd].empty()) {
            int nnd = map[nd].top();
            map[nd].pop();
            
            if (!visited[nnd]) {
                visited[nnd] = lv++;
                q.push(nnd);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << visited[i] << '\n';
    }
}