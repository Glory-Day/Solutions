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

    if (next_permutation(arr.begin(), arr.end())) {
        for (int i = 0; i < n; i++) {
            cout << arr[i] << ' ';
        }
    }
    else {
        cout << -1;
    }
}