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

    sort(arr.begin(), arr.end());

    int answer = 1;
    for (int i = 0; i < n; i++) {
        if (answer < arr[i]) break;
        answer += arr[i];
    }

    cout << answer;
}