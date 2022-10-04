#include <iostream>

using namespace std;

int arr[2001];
bool cache[2001][2001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        cache[i][i] = true;
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= n - i; j++) {
            int b = j, e = j + i;
            int l = b + 1, r = e - 1;

            if (l > r || cache[l][r]) {
                cache[b][e] = (arr[b] == arr[e]);
            }
        }
    }

    cin >> n;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        cout << cache[a][b] << '\n';
    }
}