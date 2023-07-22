#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
    int t;
    cin >> t;

    while (t--) {
        ll n;
        cin >> n;

        vector<int> cnt(n + 1, 0);
        vector<int> mx(n + 1, 0);
        for (int i = 0; i < n; i++) {
            ll input;
            cin >> input;

            if (input > n) {
                continue;
            }

            cnt[input]++;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j += i) {
                mx[j] += cnt[i];
            }
        }

        int answer = -1;
        for (int i = 1; i <= n; i++) {
            answer = max(answer, mx[i]);
        }

        cout << answer << '\n';
    }

    return 0;
}