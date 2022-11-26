#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        if (n % 2 == 0) {
            for (int i = 0; i < n - 2; i++) {
                cout << 2 << ' ';
            }
            cout << 1 << ' ' << 3;
        }
        else {
            for (int i = 0; i < n; i++) {
                cout << 1 << ' ';
            }
        }

        cout << '\n';
    }
}