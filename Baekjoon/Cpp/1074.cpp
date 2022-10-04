#include <iostream>

using namespace std;

int r, c, cnt;

bool check(int by, int bx, int ey, int ex) {
    if (r >= by && r <= ey && c >= bx && c <= ex) return true;
    return false;
}

void dfs(int y, int x, int len) {
    if (!check(y, x, y + len - 1, x + len - 1)) {
        cnt += len * len - 1;
        return;
    }

    if (len == 1) {
        if (y == r && x == c) cout << cnt;
        return;
    }

    len /= 2;
    dfs(y, x, len), cnt++;
    dfs(y, x + len, len), cnt++;
    dfs(y + len, x, len), cnt++;
    dfs(y + len, x + len, len), cnt++;
}

int main() {
    int n;
    cin >> n >> r >> c;
    
    n = 1 << n;

    dfs(0, 0, n);
}