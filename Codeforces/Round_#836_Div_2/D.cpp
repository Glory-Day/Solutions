#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        if (n % 2 == 1) {
            cout << 4 * n << ' ';
        }

        for (int i = 1; i <= n / 2 - 1; i++) {
            cout << 4 * n - i << ' ' << 4 * n + i << ' ';
        }

        cout << 3 * n << ' ' << 5 * n << '\n';
    }
}