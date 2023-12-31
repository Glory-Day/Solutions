#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

pii direction[4] = { { -1,0 },{ 1,0 },{ 0,-1 },{ 0,1 } };

int n,m;
int map[8][8];
int copy_map[8][8];
int answer = -1;

bool check(int y, int x) {
    return 0 <= y && y < n && 0 <= x && x < m;
}

void bfs() {
    queue<pii> q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (copy_map[i][j] == 2) {
                q.push({ i,j });
            }
        }
    }

    while (!q.empty()) {
        pii p = q.front();
        q.pop();

        for (auto i: direction) {
            int ny = i.first + p.first;
            int nx = i.second + p.second;

            if (check(ny, nx) && copy_map[ny][nx] == 0) {
                copy_map[ny][nx] = 2;
                q.push({ ny,nx });
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (copy_map[i][j] == 0) {
                cnt++;
            }
        }
    }

    answer = max(answer, cnt);
}

 void dfs(int lv) {
    if (lv == 3) {
        copy(&map[0][0], &map[0][0] + 64, &copy_map[0][0]);
        bfs();
        return;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 0) {
                map[i][j] = 1;
                dfs(lv + 1);
                map[i][j] = 0;
            }
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    dfs(0);
    
    cout << answer;
}