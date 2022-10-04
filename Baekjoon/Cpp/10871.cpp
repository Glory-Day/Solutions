#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        if (input < m) {
            cout << input << ' ';
        }
    }
}