#include <iostream>
#include <utility>
#include <queue>
#include <string>

using namespace std;

typedef pair<int, int> pii;

pii direction[4] = { { -1,0 },{ 1,0 },{ 0,-1 },{ 0,1 } };

int n, m;
int map[100][100];
bool visited[100][100];

queue<pii> q;

bool check(int y, int x) {
    return 0 <= y && y < n && 0 <= x && x < m;
}

void bfs() {
    q.push({ 0,0 });

    while(!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (auto i: direction) {
            int ny = y + i.first;
            int nx = x + i.second;

            if (check(ny, nx) && map[ny][nx] && !visited[ny][nx]) {
                map[ny][nx] = map[y][x] + 1;
                visited[ny][nx] = true;
                q.push({ ny,nx });
            }
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string input;
        cin >> input;

        for (int j = 0; j < m; j++) {
            map[i][j] = input[j] - '0';
        }
    }

    map[0][0] = 1;

    bfs();

    cout << map[n - 1][m - 1];
}