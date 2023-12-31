#include <iostream>
#include <string>
#include <queue>
#include <utility>

using namespace std;

typedef pair<int, int> pii;

typedef struct _point {
    int y, x, b;
} point;

pii direction[4] = { { 1,0 },{ -1,0 },{ 0,1 },{ 0,-1 } };

int n, m;
bool map[1001][1001];
int visited[1001][1001][2];

bool check(int y, int x) {
    return 1 <= y && y <= n && 1 <= x && x <= m;
}

int bfs() {
    queue<point> q;
    q.push({ 1,1,1 });

    visited[1][1][1] = 1;

    while (!q.empty()) {
        int y = q.front().y;
        int x = q.front().x;
        int b = q.front().b;

        q.pop();

        if (y == n && x == m) {
            return visited[y][x][b];
        }

        for (auto i: direction) {
            int ny = y + i.first;
            int nx = x + i.second;

            if (check(ny, nx)) {
                if (map[ny][nx] && b) {
                    visited[ny][nx][b - 1] = visited[y][x][b] + 1;
                    q.push({ ny,nx,b - 1 });
                }
                if (!map[ny][nx] && !visited[ny][nx][b]) {
                    visited[ny][nx][b] = visited[y][x][b] + 1;
                    q.push({ ny,nx,b });
                }
            }
        }
    }

    return -1;
}

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        string input;
        cin >> input;
        for (int j = 1; j <= m; j++) {
            map[i][j] = input[j - 1] - '0';
        }
    }

    cout << bfs();
}