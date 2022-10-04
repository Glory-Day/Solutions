#include <iostream>

using namespace std;

char map[6562][6562];

void f(int xb, int yb, int xe, int ye) {
    int len = (xe - xb) / 3;

    if (len == 1) {
        int c = 1;
        for (int i = yb; i < ye; i++) {
            for (int j = xb; j < xe; j++) {
                if (c == 5) map[i][j] = ' ';
                else map[i][j] = '*';
                c++;
            }
        }
        return;
    }
    else {
        f(xb, yb, xe - len * 2, ye - len * 2);
        f(xb + len, yb, xe - len, ye - len * 2);
        f(xb + len * 2, yb, xe, ye - len * 2);
        f(xb, yb + len, xe - len * 2, ye - len);
        f(xb + len * 2, yb + len, xe, ye - len);
        f(xb, yb + len * 2, xe - len * 2, ye);
        f(xb + len, yb + len * 2, xe - len, ye);
        f(xb + len * 2, yb + len * 2, xe, ye);

        for (int i = yb + len; i < ye - len; i++) {
            for (int j = xb + len; j < xe - len; j++) {
                map[i][j] = ' ';
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    f(0, 0, n, n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << map[i][j];
        }
        cout << '\n';
    }
}