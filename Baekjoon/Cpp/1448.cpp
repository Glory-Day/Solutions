#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> arr;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        arr.push_back(input);
    }

    sort(arr.begin(), arr.end());

    int answer = -1;
    for (int i = n - 3; i >= 0; i--) {
        if (arr[i + 2] < arr[i + 1] + arr[i]) {
            answer = arr[i + 2] + arr[i + 1] + arr[i];
            break;
        }
    }

    cout << answer;
}