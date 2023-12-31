#include <iostream>

using namespace std;

int answer[3];
int map[2187][2187];

void f(int y, int x, int n) {
    bool check = true;
    int temp = map[y][x];
    int ny = y;
    for (int i = 0; check && i < n; i++, ny++) {
        int nx = x;
        for (int j = 0; check && j < n; j++, nx++) {
            if (temp != map[ny][nx]) {
                check = false;
            }
        }
    }

    if (check) {
        answer[temp]++;
    }
    else {
        int len = n / 3;
        f(y, x, len);
        f(y, x + len, len);
        f(y, x + len * 2, len);
        f(y + len, x, len);
        f(y + len, x + len, len);
        f(y + len, x + len * 2, len);
        f(y + len * 2, x, len);
        f(y + len * 2, x + len, len);
        f(y + len * 2, x + len * 2, len);
    }
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
            map[i][j]++;
        }
    }

    f(0, 0, n);

    for (int& i: answer) {
        cout << i << '\n';
    }
}