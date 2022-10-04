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

    reverse(arr.begin(), arr.end());

    int answer = 0;
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] <= arr[i + 1]) {
            int tmp = arr[i + 1] - arr[i] + 1;
            arr[i + 1] -= tmp;
            answer += tmp;
        }
    }

    cout << answer;
}