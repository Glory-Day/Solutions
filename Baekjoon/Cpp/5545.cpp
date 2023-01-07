#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    int a, b, c;
    cin >> a >> b >> c;

    vector<int> arr;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        arr.push_back(input);
    }

    sort(arr.begin(), arr.end());

    int answer = c / a;
    for (int i = n - 1; i >= 0; i--) {
        c += arr[i];
        a += b;
        int average = c / a;

        answer = max(answer, average);
    }

    cout << answer;
}