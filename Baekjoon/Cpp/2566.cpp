#include <iostream>

using namespace std;

int main() {
    int map[10][10];

    int mx = -1, x, y;
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            cin >> map[i][j];

            if (mx < map[i][j]) {
                mx = map[i][j];
                y = i, x = j;
            }
        }
    }

    cout << mx << '\n';
    cout << y << ' ' << x;
}