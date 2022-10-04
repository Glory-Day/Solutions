#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> arr;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        arr.push_back(input);
    }

    sort(arr.begin(), arr.end());

    vector<int> arr2(n - 1);
    for (int i = 0; i < n - 1; i++) {
        arr2[i] = arr[i + 1] - arr[i];
    }

    sort(arr2.begin(), arr2.end());

    int answer = 0;
    for (int i = 0; i < n - k; i++) {
        answer += arr2[i];
    }

    cout << answer;
}