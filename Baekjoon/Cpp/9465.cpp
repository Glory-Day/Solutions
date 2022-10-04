#include <iostream>
#include <algorithm>

using namespace std;

int cache[2][100001];

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        cache[0][0] = cache[1][0] = 0;

        for (int i = 1; i <= n; i++) {
            cin >> cache[0][i];
        }
        for (int i = 1; i <= n; i++) {
            cin >> cache[1][i];
        }

        for (int i = 2; i <= n; i++) {
            cache[0][i] += max(cache[1][i - 1], cache[1][i - 2]);
            cache[1][i] += max(cache[0][i - 1], cache[0][i - 2]);
        }

        cout << max(cache[0][n], cache[1][n]) << '\n';
    }
}