#include <iostream>
#include <climits>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

pii direction[8] = { { -2,-1 },{ -2,1 },{ -1,-2 }, { -1,2 },{ 2,-1 },{ 2,1 },{ 1,-2 },{ 1,2 } };

int n;
int map[300][300];
int visited[300][300];

bool check(int y, int x) {
    return 0 <= y && y < n && 0 <= x && x < n;
}

int bfs(pii a, pii b) {
    queue<pii> q;
    q.push(a);

    map[a.first][a.second] = 1;
    visited[a.first][a.second] = true;

    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;

        q.pop();

        if (y == b.first && x == b.second) {
            return map[y][x] - 1;
        }

        for (auto i: direction) {
            int ny = y + i.first;
            int nx = x + i.second;

            if (check(ny, nx) && !visited[ny][nx]) {
                map[ny][nx] = min(map[y][x] + 1, map[ny][nx]);
                visited[ny][nx] = true;

                q.push({ ny,nx });
            }
        }
    }

    return 0;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        pii a, b;
        cin >> n >> a.first >> a.second >> b.first >> b.second;

        fill(map[0], map[300], INT_MAX);
        fill(visited[0], visited[300], false);

        cout << bfs(a, b) << '\n';
    }
}