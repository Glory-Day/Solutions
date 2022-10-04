#include <iostream>
#include <utility>

using namespace std;

typedef pair<int, int> pii;

pii answer;
bool map[128][128];

void f(int y, int x, int len) {
    bool check = true;
    bool temp = map[y][x];
    int ny = y;
    for (int i = 0; check && i < len; i++, ny++) {
        int nx = x;
        for (int j = 0; check && j < len; j++, nx++) {
            if (temp != map[ny][nx]) {
                check = false;
            }
        }
    }

    if (check) {
        if (temp) answer.second++;
        else answer.first++;
        return;
    }
    else {
        len /= 2;
        f(y, x, len);
        f(y, x + len, len);
        f(y + len, x, len);
        f(y + len, x + len, len);
    }
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }

    f(0, 0, n);

    cout << answer.first << '\n' << answer.second;
}