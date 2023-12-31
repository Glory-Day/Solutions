#include <iostream>

using namespace std;

int cache[1001];

int main() {
    int n;
    cin >> n;

    cache[0] = cache[1] = 1;

    for (int i = 2; i <= n; i++) {
        cache[i] = (cache[i - 1] + cache[i - 2]) % 10007;
    }

    cout << cache[n] << '\n';
}