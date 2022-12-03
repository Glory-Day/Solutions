#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, x;
        cin >> n >> x;

        if (n % x) {
            cout << -1 << '\n';
        }
        else {
            vector<int> answer(n + 1, 0);
            for (int i = 1; i <= n; i++) {
                answer[i] = i;
            }

            answer[1] = x;
            answer[n] = 1;

            int a = n / x;
            int b = 2;
            while (a != 1) {
                if (a % b == 0) {
                    answer[x] = x * b;
                    x *= b;
                    a /= b;
                }
                else {
                    b++;
                }
            }

            for (int i = 1; i <= n; i++) {
                cout << answer[i] << ' ';
            }

            cout << '\n';
        }
    }
}