#include <iostream>
#include <cmath>
#include <memory.h>

using namespace std;

bool cache[10001];

void check(int n) {
    memset(cache, 1, sizeof(cache));

    cache[0] = cache[1] = false;

    int sqrtn = int(sqrt(n));

    for (int i = 2; i <= sqrtn; i++) {
        if(cache[i]) {
            for (int j = i * i; j <= n; j += i) {
                cache[j] = false;
            }
        }
    }
}

int main() {
    check(10000);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;

        int a, b;
        for (int j = 2; j <= input / 2; j++) {
            if (cache[j] && cache[input - j]) {
                a = j;
                b = input - j;
            }
        }

        cout << a << ' ' << b << '\n';
    }
}