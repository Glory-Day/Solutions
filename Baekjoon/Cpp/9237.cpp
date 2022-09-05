#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

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

    sort(arr.begin(), arr.end(), greater<int>());

    int answer = 0;
    for (int i = 0; i < n; i++) {
        arr[i] -= n - i;
        arr[i] = (arr[i] < 0) ? 0 : arr[i];
        answer = max(arr[i], answer);
    }

    cout << answer + n + 2;
}