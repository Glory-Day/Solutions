#include <iostream>
#include <climits>
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

    int answer = INT_MAX;
    int b = 0, e = 0, sum = arr[0];

    while (b <= e && e < n) {
        if (sum > m) {
            answer = min(answer, e - b + 1);
            sum -= arr[b++];
        }
        else if (sum == m) {
            answer = min(answer, e - b + 1);
            sum += arr[++e];
        }
        else sum += arr[++e];
    }

    if (answer == INT_MAX) cout << 0;
    else cout << answer;
}