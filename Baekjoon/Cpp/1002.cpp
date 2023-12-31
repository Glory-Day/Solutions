#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x1, y1, r1, x2, y2, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

        int d = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
        int rs1 = (r2 - r1) * (r2 - r1);
        int rs2 = (r2 + r1) * (r2 + r1);

        if (d == 0) {
            if (rs1 == 0) cout << -1 << '\n';
            else cout << 0 << '\n';
        }
        else if (d == rs1 || d == rs2) {
            cout << 1 << '\n';
        }
        else if (rs1 < d && d < rs2) {
            cout << 2 << '\n';
        }
        else {
            cout << 0 << '\n';
        }
    }
}