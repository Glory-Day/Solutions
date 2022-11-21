#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <utility>

using namespace std;

typedef pair<int, int> pii;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        string a, b;
        cin >> a >> b;

        pii d = { 0,0 };
        for (int i = 0; i < n; i++) {
            if (a[i] != b[i]) {
                if (a[i] == 'W') {
                    d.first++;
                }
                else {
                    d.second++;
                }
            }
        }

        int answer = min(d.first, d.second) + abs(d.first - d.second);

        cout << answer << '\n';
    }
}