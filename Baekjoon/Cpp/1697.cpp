#include <iostream>
#include <climits>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

int n, m;
int map[100001];
bool visited[100001];

bool check(int x) {
    return 0 <= x && x <= 100000;
}

void bfs() {
    queue<int> q;
    q.push(n);
    map[n] = 0;
    visited[n] = true;

    while (!q.empty()) {
        int x = q.front();
        q.pop();

        if (x == m) break;

        for (int i = 0; i < 3; i++) {
            int nx = x;

            switch (i) {
                case 0: nx++; break;
                case 1: nx--; break;
                case 2: nx *= 2; break;
            }

            if (check(nx) && !visited[nx]) {
                map[nx] = min(map[x] + 1, map[nx]);
                visited[nx] = true;

                q.push(nx);
            }
        }
    }
}

int main() {
    cin >> n >> m;

    fill(map, map + 100001, INT_MAX);

    bfs();

    cout << map[m];
}