#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>

using namespace std;

int cache[1000001];
int map[1000001];

int f(int n) {
    if (n <= 0) return INT_MAX;
    if (cache[n]) return cache[n];

    int a = (n % 3 == 0) ? f(n / 3) : INT_MAX;
    int b = (n % 2 == 0) ? f(n / 2) : INT_MAX;
    int c = f(n - 1);

    int mn;
    if (a < b) {
        if (a < c) mn = a, map[n] = n / 3;
        else mn = c, map[n] = n - 1;
    }
    else {
        if (b < c) mn = b, map[n] = n / 2;
        else mn = c, map[n] = n - 1;
    }

    return cache[n] = mn + 1;
}

int main() {
    int n;
    cin >> n;

    cache[1] = 1;
    map[1] = 1;

    int answer = f(n);
    cout << answer - 1 << '\n';

    int nd = n;
    while (nd != 1) {
        cout << nd << ' ';
        nd = map[nd];
    }
    cout << nd << ' ';
}