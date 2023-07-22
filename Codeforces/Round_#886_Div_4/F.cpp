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
        int n;
        cin >> n;

        vector<int> cnt(n + 1, 0);
        for (int i = 0; i < n; i++) {
            int input;
            cin >> input;

            if (input > n) {
                continue;
            }

            for (int j = input; j <= n; j += input) {
                cnt[j]++;
            }
        }

        int answer = -1;
        for (int i = 1; i <= n; i++) {
            answer = max(answer, cnt[i]);
        }

        cout << answer << '\n';
    }

    return 0;
}