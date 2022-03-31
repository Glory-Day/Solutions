#include <iostream>

using namespace std;

int map[15][15];
int len, answer;

bool check(int x, int y) {
    return (0 <= x) && (x <= len - 1) && (0 <= y) && (y <= len - 1);
}

void checkTrue(int x, int y) {
    for (int i = 0; i < len; i++) {
        map[i][y]++;
        map[x][i]++;
    }

    for (int i = x, j = y; check(i, j); i++, j++) {
        map[i][j]++;
    }
    for (int i = x, j = y; check(i, j); i--, j++) {
        map[i][j]++;
    }
    for (int i = x, j = y; check(i, j); i++, j--) {
        map[i][j]++;
    }
    for (int i = x, j = y; check(i, j); i--, j--) {
        map[i][j]++;
    }
}

void checkFalse(int x, int y) {
    for (int i = 0; i < len; i++) {
        map[i][y]--;
        map[x][i]--;
    }

    for (int i = x, j = y; check(i, j); i++, j++) {
        map[i][j]--;
    }
    for (int i = x, j = y; check(i, j); i--, j++) {
        map[i][j]--;
    }
    for (int i = x, j = y; check(i, j); i++, j--) {
        map[i][j]--;
    }
    for (int i = x, j = y; check(i, j); i--, j--) {
        map[i][j]--;
    }
}

void f(int x, int y) {
    if (y == len - 1) {
        answer++;
        return;
    }

    checkTrue(x, y);

    for (int i = 0; i < len; i++) {
        if (!map[i][y + 1]) {
            f(i, y + 1);
        }
    }

    checkFalse(x, y);
}

int main() {
    int n;
    cin >> n;

    len = n;

    for (int i = 0; i < n; i++) {
        f(i, 0);
    }

    cout << answer;
}