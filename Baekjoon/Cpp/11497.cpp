#include <iostream>
#include <cmath>
#include <vector>
#include <deque>
#include <algorithm>
#include <functional>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> arr;
        for (int i = 0; i < n; i++) {
            int input;
            cin >> input;
            arr.push_back(input);
        }

        sort(arr.begin(), arr.end(), greater<int>());

        deque<int> dq;
        if (n % 2 == 1) dq.push_front(arr.front());

        for (int i = n % 2; i < n; i += 2) {
            dq.push_back(arr[i]);
            dq.push_front(arr[i + 1]);
        }

        int answer = abs(dq.front() - dq.back());
        for (int i = 0; i < n - 1; i++) {
            answer = max(abs(dq[i] - dq[i + 1]), answer);
        }

        cout << answer << '\n';
    }
}