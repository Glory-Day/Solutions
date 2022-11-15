#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <functional>

using namespace std;

typedef pair<int, int> pii;

int main() {
    int n, m;
    cin >> n >> m;

    int mx = 0;
    vector<int> arr;
    for (int i = 0; i < m; i++) {
        int input;
        cin >> input;
        arr.push_back(input);
    }

    sort(arr.begin(), arr.end(), greater<int>());

    pii answer = { 0,-1 };
    for (int i = m; i > 0; i--) {
        int tmp = min(n, i) * arr[i - 1];
        if (answer.second < tmp) {
            answer.first = arr[i - 1];
            answer.second = tmp;
        }
    }

    cout << answer.first << ' ' << answer.second;
}