#include <iostream>

using namespace std;

#define MOD 9901

int cache[100001];

int main() {
    int n;
    cin >> n;

    cache[0] = 1;
    cache[1] = 3;

    for (int i = 2; i <= n; i++) {
        cache[i] = (cache[i - 2] + cache[i - 1] * 2) % MOD;
    }

    cout << cache[n];
}