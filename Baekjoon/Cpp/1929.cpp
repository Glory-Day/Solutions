#include <iostream>
#include <cmath>
#include <memory.h>

using namespace std;

bool cache[1000001];

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
    int n, m;
    cin >> n >> m;

    check(m);

    for (int i = n; i <= m; i++) {
        if (cache[i]) {
            cout << i << '\n';
        }
    }
}