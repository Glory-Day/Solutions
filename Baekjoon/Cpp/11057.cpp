#include <iostream>

using namespace std;

int n;
int cache[10];

int main() {
    cin >> n;

    for (int i = 0; i <= 9; i++) {
        cache[i] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int i = 8; i >= 0; i--) {
            cache[i] = (cache[i] + cache[i + 1]) % 10007;
        }
    }

    cout << cache[0];
}