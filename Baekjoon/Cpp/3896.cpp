#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    vector<bool> cache1(1300000, true);
    cache1[0] = cache1[1] = false;

    for (int i = 2; i < 1300000; i++) {
        if (cache1[i] == false) {
            continue;
        }

        for (int j = 2; i * j < 1300000; j++) {
            cache1[i * j] = false;
        }
    }

    vector<int> cache2;
    for (int i = 0; i < 1300000; i++) {
        if (cache1[i]) {
            cache2.push_back(i);
        }
    }

    while (t--) {
        int n;
        cin >> n;

        if (cache1[n] || n == 1) {
            cout << 0 << '\n';
        }
        else {
            int tmp = upper_bound(cache2.begin(), cache2.end(), n) - cache2.begin();
            cout << cache2[tmp] - cache2[tmp - 1] << '\n';
        }
    }
}