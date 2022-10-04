#include <iostream>
#include <cmath>
#include <memory.h>

using namespace std;

bool cache[300001];

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
    check(300000);

    while (true) {
        int n;
        cin >> n;

        if (n == 0) break;
        int answer = 0;
        for (int i = n + 1; i <= 2 * n; i++) {
            answer += (cache[i]) ? 1 : 0;
        }

        cout << answer << '\n';
    }
}