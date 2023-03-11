#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> arr = { 0 };
    for (int i = 1; i <= n; i++) {
        arr.push_back(i);
    }

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        vector<int> tmp;
        for (int j = c; j <= b; j++) {
            tmp.push_back(arr[j]);
        }

        for (int j = a; j <= c - 1; j++) {
            tmp.push_back(arr[j]);
        }

        for (int j = a, k = 0; j <= b; j++, k++) {
            arr[j] = tmp[k];
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << arr[i] << ' ';
    }
}