#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int cache[1000001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int mx = 0;
    for (int i = 1; i <= n; i++) {
        int input;
        cin >> input;
        cache[input] = cache[input - 1] + 1;
        mx = max(mx, cache[input - 1] + 1);
    }

    cout << n - mx;
}