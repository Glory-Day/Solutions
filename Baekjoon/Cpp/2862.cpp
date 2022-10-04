#include <iostream>

using namespace std;

typedef long long ll;

ll cache[81];

int main() {
    ll n;
    cin >> n;

    cache[1] = cache[2] = 1;

    for (int i = 3; i < 80; i++) {
        cache[i] = cache[i - 1] + cache[i - 2];
    }

    while (true) {
        ll tmp = n;
        for (int i = 1; i < 80; i++) {
            if (tmp < cache[i]) {
                tmp = cache[i - 1];
                break;
            }
        }

        if (tmp == n) break;

        n -= tmp;
    }

    cout << n;
}