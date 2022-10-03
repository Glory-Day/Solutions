#include <iostream>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

pii direction[4] = { { -1,0 },{ 1,0 },{ 0,-1 },{ 0,1 } };

int answer = -1;
int n, m;
char map[21][21];
bool visited[100];

bool check(int y, int x) {
    return 0 <= y && y < n && 0 <= x && x < m;
}

void dfs(int y, int x, int lv) {
    answer = max(answer, lv);
    visited[map[y][x] - 'A'] = true;

    for (auto i: direction) {
        int ny = y + i.first;
        int nx = x + i.second;

        if (check(ny, nx) && !visited[map[ny][nx] - 'A']) {
            dfs(ny, nx, lv + 1);
        }
    }

    visited[map[y][x] - 'A'] = false;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            map[i][j] = s[j];
        }
    }
    
    dfs(0, 0, 1);

    cout << answer;
}