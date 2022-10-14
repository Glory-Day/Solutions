#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> arr;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        arr.push_back(input);
    }

    sort(arr.begin(), arr.end());

    int answer = arr.back() - arr.front();

    for (int i = n - 1; i >= 1; i--) {
        arr[i] = arr[i] - arr[i - 1];
    }

    arr[0] = 0;

    sort(arr.begin(), arr.end());

    for (int i = n - 1; m > 1; i--, m--) {
        answer -= arr[i];
    }

    cout << answer;
}