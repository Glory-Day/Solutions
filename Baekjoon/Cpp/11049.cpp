#include <iostream>
#include <climits>
#include <algorithm>
#include <utility>

using namespace std;

typedef pair<int, int> pii;

pii arr[501];
int cache[501][501];

int f(int b, int e) {
    if (cache[b][e] != INT_MAX) return cache[b][e];
    if (b + 1 == e) return cache[b][e] = arr[b].first * arr[b].second * arr[e].second;

    pii lp, rp;
    int l, r;
    for (int i = b; i < e; i++) {
        l = r = 0;

        lp = arr[b];
        rp = arr[e];

        if (b != i) {
            lp = { arr[b].first,arr[i].second };
            l = f(b, i);
        }

        if (i + 1 != e) {
            rp = { arr[i + 1].first,arr[e].second };
            r = f(i + 1, e);
        }

        int sum = lp.first * lp.second * rp.second;

        cache[b][e] = min(l + r + sum, cache[b][e]);
    }

    return cache[b][e];
}

int main() {
    fill(cache[0], cache[501], INT_MAX);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        arr[i] = { a,b };
    }

    f(1, n);

    cout << cache[1][n];
}