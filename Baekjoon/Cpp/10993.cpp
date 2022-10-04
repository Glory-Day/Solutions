#include <iostream>
#include <cmath>

using namespace std;

void dfs(int y, int x, int b, int e, int mid, int lv) {
    int l = mid - abs(b - y);
    int r = mid + abs(b - y);

    if (y == e && x >= l && x <= r) cout << "*";
    else if (x == l || x == r) {
        if ((b > e ? b : e) >= y && (b < e ? b : e) <= y) cout << "*";
        else cout << " ";
    }
    else {
        if (lv == 1) cout << " ";
        else dfs(y, x, lv % 2 == 0 ? e + 1 : e - 1, (b + e) / 2, mid, lv - 1);
    }
}

int main() {
    int n;
    cin >> n;

    int h = (int)pow(2, n) - 1;
    int w = h * 2 - 1;
    int mid = w / 2;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < (n % 2 == 0 ? w - i : w - (mid - i)); j++) {
            if (n % 2 == 0) dfs(i, j, h - 1, 0, mid, n);
            else dfs(i, j, 0, h - 1, mid, n);
        }
        cout << "\n";
    }
}