#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
#include <utility>
#include <functional>

using namespace std;

typedef pair<int, int> pii;

int main() {
    int n, l, k;
    cin >> n >> l >> k;

    vector<int> arr;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;

        int tmp = 0;
        if (b <= l) {
            tmp = 140;
        }
        else if (a <= l) {
            tmp = 100;
        }

        arr.push_back(tmp);
    }

    sort(arr.begin(), arr.end(), greater<int>());

    int answer = 0;
    for (int i = 0; i < k; i++) {
        answer += arr[i];
    }

    cout << answer;
}