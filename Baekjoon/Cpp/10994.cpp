#include <iostream>

using namespace std;

char map[501][501];

void dfs(int y, int x, int lv) {
    if (lv == 1) {
        map[y][x] = '*';
        return;
    }

    int len = 4 * (lv - 1) + 1;

    for (int i = y; i < y + len; i++) {
        map[x][i] = '*';
        map[x + len - 1][i] = '*';
    }

    for (int i = x; i < x + len; i++) {
        map[i][y] = '*';
        map[i][y + len - 1] = '*';
    }

    dfs(y + 2, x + 2, lv - 1);
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < 4 * (n - 1) + 1; i++) {
        for (int j = 0; j < 4 * (n - 1) + 1; j++) {
            map[i][j] = ' ';
        }
    }

    dfs(0, 0, n);

    for (int i = 0; i < 4 * (n - 1) + 1; i++) {
        for (int j = 0; j < 4 * (n - 1) + 1; j++) {
            cout << map[i][j];
        }
        cout << "\n";
    }
}