#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

pii direction[4] = { { -1,0 },{ 1,0 },{ 0,-1 },{ 0,1 } };

int n, m;
bool map[50][50];

bool check(int y, int x) {
    return 0 <= y && y < n && 0 <= x && x < m;
}

int dfs(int y, int x) {
    map[y][x] = false;

    for (auto i: direction) {
        int ny = y + i.first;
        int nx = x + i.second;

        if (check(ny, nx) && map[ny][nx]) {
            dfs(ny, nx);
        }
    }

    return 1;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int k;
        cin >> n >> m >> k;

        for (int i = 0; i < k; i++) {
            int a, b;
            cin >> a >> b;
            map[a][b] = true;
        }

        int answer = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (map[i][j]) answer += dfs(i, j);
            }
        }

        cout << answer << '\n';
    }
}