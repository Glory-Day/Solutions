#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int cache[1001][1001];

int main() {
    string a, b;
    cin >> a >> b;

    int n = a.length(), m = b.length();

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i - 1] == b[j - 1]) cache[i][j] = cache[i - 1][j - 1] + 1;
            else cache[i][j] = max(cache[i - 1][j], cache[i][j - 1]);
        }
    }

    cout << cache[n][m];
}