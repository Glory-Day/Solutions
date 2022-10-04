#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    deque<int> arr;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        arr.push_back(input);
    }

    sort(arr.begin(), arr.end());

    int answer = 0;
    int tmp = arr.front();
    while (!arr.empty()) {
        int sum = arr.front() - tmp;
        if (sum < k) {
            arr.pop_front();
        }
        else {
            answer++;
            tmp = arr.front();
        }
    }

    cout << answer + 1;
}