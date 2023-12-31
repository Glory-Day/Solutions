#include <iostream>
#include <queue>

using namespace std;

int node[101];
int visited[101];

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= 100; i++) {
        node[i] = i;
        visited[i] = -1;
    }

    for (int i = 0; i < n + m; i++) {
        int a, b;
        cin >> a >> b;
        node[a] = b;
    }

    visited[1] = 0;
    queue<int> q;
    q.push(1);

    while (!q.empty()) {
        int nd = q.front();
        q.pop();

        for (int i = 1; i <= 6; i++) {
            int nnd = nd + i;

            if (nnd <= 100 && visited[node[nnd]] == -1) {
                visited[node[nnd]] = visited[nd] + 1;
                q.push(node[nnd]);
            }
        }
    }

    cout << visited[100];
}