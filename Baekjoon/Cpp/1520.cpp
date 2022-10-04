#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int n, m;
int map[501][501];
int cache[501][501];

pii d[4] = { { -1,0 },{ 1,0 },{ 0,-1 },{ 0,1 } };

int dfs(int y, int x) {
    if (cache[y][x] == -1) {
        cache[y][x] = 0;
        for (int i = 0; i < 4; i++) {
            int dy = d[i].first + y;
            int dx = d[i].second + x;

            if (0 <= dy && dy < n && 0 <= dx && dx < m && map[y][x] > map[dy][dx]) {
                cache[y][x] += dfs(dy, dx);
            }
        }
    }

    return cache[y][x];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    fill(cache[0], cache[501], -1);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    cache[n - 1][m - 1] = 1;

    int answer = dfs(0, 0);

    cout << answer;
}