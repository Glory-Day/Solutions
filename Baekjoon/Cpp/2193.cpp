#include <iostream>

using namespace std;

typedef long long ll;

ll cache[91];

int main() {
    int n;
    cin >> n;

    cache[1] = cache[2] = 1;

    for (int i = 3; i <= n; i++) {
        cache[i] = cache[i - 2] + cache[i - 1];
    }

    cout << cache[n];
}