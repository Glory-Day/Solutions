#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    int cache[1001][3];

    cin >> cache[0][0] >> cache[0][1] >> cache[0][2];

    for (int i = 1; i < n; i++) {
        cin >> cache[i][0] >> cache[i][1] >> cache[i][2];

        cache[i][0] += min(cache[i - 1][1], cache[i - 1][2]);
        cache[i][1] += min(cache[i - 1][0], cache[i - 1][2]);
        cache[i][2] += min(cache[i - 1][0], cache[i - 1][1]);
    }

    cout << min(cache[n - 1][0], min(cache[n - 1][1], cache[n - 1][2]));
}