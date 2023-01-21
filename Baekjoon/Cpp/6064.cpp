#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }

    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m, x, y;
        cin >> n >> m >> x >> y;

        int mx = lcm(n, m);
        while (x <= mx) {
            if ((x - 1) % m + 1 == y || x > mx) {
                break;
            }

            x += n;
        }

        if (x > mx) {
            cout << -1 << '\n';
        }
        else {
            cout << x << '\n';
        }
    }
}