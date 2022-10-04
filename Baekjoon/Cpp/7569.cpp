#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

typedef struct _point {
    int x, y, z;
} point;

point direction[6] = { { 1,0,0 },{ -1,0,0 },
                       { 0,1,0 },{ 0,-1,0 },
                       { 0,0,1 },{ 0,0,-1 } };

int n, m, k;
int map[100][100][100];
bool visited[100][100][100];

bool check(int x, int y, int z) {
    bool chk1 = (0 <= x && x < n);
    bool chk2 = (0 <= y && y < m);
    bool chk3 = (0 <= z && z < k);

    return chk1 && chk2 && chk3;
}

void bfs() {
    queue<point> q;

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < m; j++) {
            for (int l = 0; l < n; l++) {
                if (map[i][j][l] == 1) {
                    q.push({ l,j,i });
                    visited[i][j][l] = true;
                }
                else if (map[i][j][l] == -1) {
                    visited[i][j][l] = true;
                }
            }
        }
    }

    while (!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int z = q.front().z;

        q.pop();

        for (auto i: direction) {
            int nx = x + i.x;
            int ny = y + i.y;
            int nz = z + i.z;

            if (check(nx, ny, nz) && !visited[nz][ny][nx]) {
                map[nz][ny][nx] = map[z][y][x] + 1;
                visited[nz][ny][nx] = true;

                q.push({ nx,ny,nz });
            }
        }
    }
}

int main() {
    cin >> n >> m >> k;

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < m; j++) {
            for (int l = 0; l < n; l++) {
                cin >> map[i][j][l];
            }
        }
    }

    bfs();

    bool chk = false;
    int answer = 0;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < m; j++) {
            for (int l = 0; l < n; l++) {
                if (map[i][j][l] == 0) {
                    chk = true;
                }
                answer = max(answer, map[i][j][l]);
            }
        }
    }

    if (chk) cout << -1;
    else cout << answer - 1;
}