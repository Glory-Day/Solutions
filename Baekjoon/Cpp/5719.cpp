#include <iostream>
#include <climits>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int n, m;
int visited[501];
int map[501][501];

void dijkstra(int b, int e) {
    priority_queue<pii> pq;
    pq.push({ 0,b });

    fill(visited, visited + 501, INT_MIN);

    while (!pq.empty()) {
        int cst = -pq.top().first;
        int nd = pq.top().second;
        pq.pop();

        if (visited[nd] != INT_MIN) continue;

        visited[nd] = cst;
        for (int i = 0; i < n; i++) {
            if (map[nd][i] != INT_MIN && visited[i] == INT_MIN) {
                pq.push({ -cst - map[nd][i],i });
            }
        }
    }
}

void bfs(int e) {
    queue<int> q;
    q.push(e);

    while (!q.empty()) {
        int nd = q.front();
        q.pop();

        for (int i = 0; i < n; i++) {
            if (visited[nd] == visited[i] + map[i][nd] && map[i][nd] != INT_MIN) {
                map[i][nd] = INT_MIN;
                q.push(i);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    while (true) {
        fill(map[0], map[500], INT_MIN);

        cin >> n >> m;
        if (n == 0 && m == 0) break;

        int b, e;
        cin >> b >> e;

        for (int i = 0; i < m; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            map[a][b] = c;
        }

        dijkstra(b, e);
        bfs(e);
        dijkstra(b, e);

        cout << ((visited[e] == INT_MIN) ? -1 : visited[e]) << '\n';
    }
}