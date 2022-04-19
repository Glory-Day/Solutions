#include <iostream>

using namespace std;

int cache[31];

int main() {
    int n;
    cin >> n;

    cache[0] = 1;
    cache[2] = 3;

    for (int i = 4; i <= n; i++) {
        cache[i] = cache[i - 2] * 3;
        for (int j = 4; j <= i; j += 2) {
            cache[i] += cache[i - j] * 2;
        }
    }

    cout << cache[n];
}