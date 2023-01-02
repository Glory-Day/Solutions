#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        arr.push_back(input);
    }

    int cnt;
    cin >> cnt;

    for (int i = 0; i < n && cnt > 0; i++) {
        int mx = -1;
        int j;
        for (int k = i; k < n && k <= i + cnt; k++) {
            if (mx < arr[k]) {
                mx = arr[k];
                j = k;
            }
        }

        for (int k = j; k > i; k--) {
            swap(arr[k - 1], arr[k]);
            cnt--;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }
}