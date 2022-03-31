#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int arr[501];
int cache[501][501];

int f(int b, int e) {
    if (cache[b][e] != INT_MAX) return cache[b][e];
    if (b == e) return cache[b][e] = 0;
    if (b + 1 == e) return cache[b][e] = arr[b] + arr[e];

    int sum = 0;
    for (int i = b; i <= e; i++) {
        sum += arr[i];
    }

    int l = 0, r = 0, d = 0;
    for (int i = b; i < e; i++) {
        l = f(b, i);
        r = f(i + 1, e);
        d = sum - (l + r);
        cache[b][e] = min(l + r, cache[b][e]);
    }

    return cache[b][e] += (l + r + d);
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        fill(cache[0], cache[501], INT_MAX);

        int n;
        cin >> n;

        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
        }

        f(1, n);

        cout << cache[1][n] << '\n';
    }
}