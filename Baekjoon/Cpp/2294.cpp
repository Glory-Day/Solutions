#include <iostream>
#include <algorithm>

using namespace std;

int cache[10001];

int main() {
    int n, m;
    cin >> n >> m;

    fill(cache + 1, cache + 10001, 10001);

    for (int i = 1; i <= n; i++) {
        int input;
        cin >> input;

        for (int j = input; j <= m; j++) {
            cache[j] = min(cache[j], cache[j - input] + 1);
        }
    }

    if (cache[m] == 10001) cout << -1 << '\n';
    else cout << cache[m] << '\n';
}