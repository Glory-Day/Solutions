#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    int d, e, f;
    d = (a == b);
    e = (b == c);
    f = (a == c);

    int sum = (d + e + f);
    if (sum == 3) {
        cout << 10000 + a * 1000;
    }
    else if (sum == 1) {
        if (d) cout << 1000 + a * 100;
        else if (e) cout << 1000 + b * 100;
        else cout << 1000 + a * 100;
    }
    else {
        cout << 100 * max(max(a, b), c);
    }
}