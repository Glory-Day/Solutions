#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> arr;
        for (int i = 0; i < n; i++) {
            int input;
            cin >> input;
            arr.push_back(input);
        }

        int mx1, mx2;
        vector<int> cp(arr);
        sort(cp.begin(), cp.end(), greater<int>());
        mx1 = cp[0], mx2 = cp[1];

        for (int i = 0; i < n; i++) {
            if (arr[i] == mx1) {
                arr[i] -= mx2;
            }
            else {
                arr[i] -= mx1;
            }

            cout << arr[i] << ' ';
        }

        cout << '\n';
    }
}