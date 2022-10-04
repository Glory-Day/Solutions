#include <iostream>
#include <algorithm>

using namespace std;

int cache[500][500];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            int input;
            cin >> input;
            cache[i][j] = input;
        }
    }

    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            cache[i][j] += max(cache[i + 1][j], cache[i + 1][j + 1]);
        }
    }

    cout << cache[0][0];
}