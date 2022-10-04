#include <iostream>
#include <climits>
#include <algorithm>

#define MAX 100001

using namespace std;

int map[101][101];
int cache[101][101];

int answer;

void dfs1(int i, int j) {
    if (cache[i][j] != MAX) {
        answer++;
        dfs1(i, cache[i][j]);
        dfs1(cache[i][j], j);
    }
}

void dfs2(int i, int j) {
    if (cache[i][j] != MAX) {
        dfs2(i, cache[i][j]);
        cout << cache[i][j] << ' ';
        dfs2(cache[i][j], j);
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            map[i][j] = MAX;
            cache[i][j] = MAX;
        }
    }

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        map[a][b] = min(map[a][b], c);
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (map[i][j] > map[i][k] + map[k][j]) cache[i][j] = k;
                map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j || map[i][j] == MAX) cout << "0";
            else cout << map[i][j];
            cout << ' ';
        }
        cout << '\n';
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j || map[i][j] == MAX) cout << "0\n";
            else {
                answer = 2;
                dfs1(i, j);
                cout << answer << ' ' << i << ' ';
                dfs2(i, j);
                cout << j << '\n';
            }
        }
    }
}