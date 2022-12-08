#include <iostream>
#include <climits>
#include <queue>
#include <vector>
#include <utility>
#include <memory.h>

using namespace std;

typedef pair<int, int> pii;

typedef struct _Position {
    int y;
    int x;
    int cst;
} Position;

typedef pair<pii, int> pipiii;

pii directions[4] = { {-1,0},{1,0},{0,1},{0,-1} };

int n;
int map[21][21];
int visited[21][21];

int mn;
int current[3];

bool check(int y, int x) {
    return 0 <= y && y < n && 0 <= x && x < n;
}

int bfs() {
    int chk = 0;
    mn = INT_MAX;

    queue<Position> q;
    q.push({ current[0],current[1],1 });

    int y, x, cst;
    while (!q.empty()) {
        y = q.front().y;
        x = q.front().x;
        cst = q.front().cst;
        q.pop();

        visited[y][x] = cst;

        int ny, nx;
        for (auto& d: directions) {
            ny = y + d.first;
            nx = x + d.second;

            if (check(ny, nx) && !visited[ny][nx] && map[ny][nx] <= current[2]) {
                if (map[ny][nx] < current[2] && map[ny][nx]) {
                    if (map[ny][nx] > 0) {
                        map[ny][nx] *= -1;
                    }

                    if (cst + 1 < mn) {
                        mn = cst + 1;
                    }

                    chk++;
                }

                visited[ny][nx] = cst + 1;
                q.push({ ny,nx,cst + 1 });
            }
        }
    }

    return chk;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
            if (map[i][j] == 9) {
                current[0] = i;
                current[1] = j;
                current[2] = 2;
                map[i][j] = 0;
            }
        }
    }

    int cnt = 0;
    int answer = 0;
    while (true) {
        int chk = bfs();

        if (!chk) {
            break;
        }

        for (int i = 0; i < n; i++) {
            bool flag = true;
            for (int j = 0; j < n; j++) {
                if (visited[i][j] == mn && map[i][j] < 0) {
                    current[0] = i;
                    current[1] = j;
                    cnt++;

                    map[i][j] = 0;

                    answer += (mn - 1);
                    flag = false;

                    if (current[2] == cnt) {
                        cnt = 0;
                        current[2]++;
                    }

                    break;
                }
            }

            if (!flag) {
                break;
            }
        }

        memset(visited, 0, sizeof(visited));
    }

    cout << answer;
}