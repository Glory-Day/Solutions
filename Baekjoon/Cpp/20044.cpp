#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    n *= 2;

    vector<int> arr;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        arr.push_back(input);
    }

    sort(arr.begin(), arr.end());

    int mn = 200001;
    for (int i = 0; i < n; i++) {
        mn = min(mn, arr[i] + arr[n - i - 1]);
    }

    cout << mn;
}