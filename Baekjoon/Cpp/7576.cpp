#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<int ,int> pii;

pii direction[4] = { { -1,0 },{ 1,0 },{ 0,-1 },{ 0,1 } };

int n, m;
int map[1000][1000];
bool visited[1000][1000];

bool check(int y, int x) {
    return 0 <= y && y < n && 0 <= x && x < m;
}

void bfs() {
    queue<pii> q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 1) {
                q.push({ i,j });
                visited[i][j] = true;
            }
            else if (map[i][j] == -1) {
                visited[i][j] = true;
            }
        }
    }

    while(!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (auto i: direction) {
            int ny = y + i.first;
            int nx = x + i.second;

            if (check(ny, nx) && !visited[ny][nx]) {
                map[ny][nx] = map[y][x] + 1;
                visited[ny][nx] = true;

                q.push({ ny,nx });
            }
        }
    }
}

int main() {
    cin >> m >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    bfs();

    bool chk = false;
    int answer = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 0) {
                chk = true;
            }
            answer = max(answer, map[i][j]);
        }
    }

    if (chk) cout << -1;
    else cout << answer - 1;
}