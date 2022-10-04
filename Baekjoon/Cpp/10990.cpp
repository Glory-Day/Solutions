#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = n; i > 0; i--) {
        for (int j = i - 2; j >= 0; j--) {
            cout << " ";
        }
        cout << "*";
        for (int j = 2 * (n - i) - 1; j > 0; j--) {
            cout << " ";
        }
        if (i < n) cout << "*";
        cout << "\n";
    }
}