#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> arr = { 0 };
    for (int i = 1; i <= n; i++) {
        arr.push_back(i);
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        reverse(arr.begin() + a, arr.begin() + b + 1);
    }

    for (int i = 1; i <= n; i++) {
        cout << arr[i] << ' ';
    }
}