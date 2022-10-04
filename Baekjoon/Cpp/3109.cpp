#include <iostream>
#include <utility>

using namespace std;

typedef pair<int, int> pii;

pii direction[3] = { { -1,1 },{ 0,1 },{ 1,1 } };

int r, c;
char map[10001][501];
bool visited[10001][501];
int answer;

bool check(int x, int y) {
    return 0 <= x && x < r && 0 <= y && y < c;
}

bool dfs(int x, int y) {
    if (y == c - 1) {
        answer++;
        return true;
    }

    for (auto& i: direction) {
        int nx = x + i.first;
        int ny = y + i.second;

        if (check(nx, ny) && !visited[nx][ny] && map[nx][ny] != 'x') {
            visited[nx][ny] = true;
            if (dfs(nx, ny)) return true;
        }
    }

    return false;
}

int main() {
    cin >> r >> c;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < r; i++) {
        visited[i][0] = true;
        dfs(i, 0);
    }

    cout << answer;
}