#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> arr;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        arr.push_back(input);
    }

    int sum = 0;
    vector<int> prefix = { 0 };
    for (auto& i: arr) {
        sum += i;
        prefix.push_back(sum);
    }

    int answer = INT_MIN;
    for (int i = 0; i < n - m + 1; i++) {
        int b = i, e = m + i;
        answer = max(answer, prefix[e] - prefix[b]);
    }

    cout << answer;
}