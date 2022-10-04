#include <iostream>

#define MOD 15746

using namespace std;

int cache[1000001];

int f(int n) {
    if (n == 0 || n == 1) return cache[1];
    else if (cache[n]) return cache[n];

    return cache[n] = (f(n - 1) + f(n - 2)) % MOD;
}

int main() {
    int n;
    cin >> n;

    cache[0] = cache[1] = 1;

    cout << f(n);
}