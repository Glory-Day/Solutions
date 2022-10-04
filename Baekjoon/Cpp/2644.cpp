#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
int map[101][101];
int visited[101];

void bfs(int b) {
    queue<int> q;
    q.push(b);

    while (!q.empty()) {
        int nd = q.front();
        q.pop();

        for (int i = 1; i <= n; i++) {
            if (map[nd][i] != 0 && !visited[i]) {
                q.push(i);
                visited[i] = visited[nd] + 1;
            }
        }
    }
}

int main() {
    cin >> n;

    int a, b;
    cin >> a >> b;

    int m;
    cin >> m;
    
    for (int i = 0; i < m; i++) {
        int c, d;
        cin >> c >> d;

        map[c][d] = map[d][c] = 1;
    }

    bfs(a);

    cout << ((visited[b] != 0) ? visited[b] : -1);
}