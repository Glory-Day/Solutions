#include <iostream>
#include <string>
#include <vector>

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

        int l = 0, r = n - 1;
        while (l < n) {
            if (arr[l] < arr[l + 1]) {
                break;
            }
            l++;
        }

        while (r >= 0) {
            if (arr[r - 1] > arr[r]) {
                break;
            }
            r--;
        }

        if (l < r) {
            cout << "NO\n";
        }
        else {
            cout << "YES\n";
        }
    }
}