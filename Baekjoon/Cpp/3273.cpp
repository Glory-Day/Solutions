#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n;

    vector<int> arr;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        arr.push_back(input);
    }

    cin >> m;

    sort(arr.begin(), arr.end());

    int b = 0, e = n - 1, answer = 0;
    while (b < e) {
        int sum = arr[b] + arr[e];

        if (sum == m) answer++, b++, e--;
        else if (sum < m) b++;
        else e--;
    }

    cout << answer;
}