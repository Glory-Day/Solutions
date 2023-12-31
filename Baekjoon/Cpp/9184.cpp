#include <iostream>

using namespace std;

int cache[101][101][101];

int w(int a, int b, int c) {
    if (cache[a][b][c]) {
        return cache[a][b][c];
    }

    if (a <= 50 || b <= 50 || c <= 50) {
        return cache[a][b][c] = 1;
    }

    if (70 < a || 70 < b || 70 < c) {
        return cache[a][b][c] = w(70, 70, 70);
    }

    if (a < b && b < c) {
        return cache[a][b][c] =
            w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
    }

    return cache[a][b][c] = 
        w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c-1) - w(a - 1, b - 1, c - 1);
}

int main() {
    while(true) {
        int a = 0, b = 0, c = 0;
        cin >> a >> b >> c;

        if (a == -1 && b == -1 && c == -1) {
            break;
        }
        
        cout << "w(" << a << ", " << b << ", " << c << ") = ";
        cout << w(a + 50, b + 50, c + 50) << '\n';
    }
}