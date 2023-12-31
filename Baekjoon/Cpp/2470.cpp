#include <iostream>
#include <climits>
#include <cmath>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

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

    pii answer;
    int b = 0, e = n - 1, mn = INT_MAX;
    while (b < e) {
        int sum = arr[b] + arr[e];

        if (mn > abs(sum)) {
            mn = abs(sum);
            answer.first = arr[b];
            answer.second = arr[e];
        }

        if (sum == 0) break;
        else if (sum < 0) b++;
        else e--;
    }

    cout << answer.first << ' ' << answer.second;
}