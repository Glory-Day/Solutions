#include <iostream>

using namespace std;

int nums[10];

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int answer = 0;
    for (int i = n - 1; i >= 0; i--) {
        answer += (k / nums[i]);
        k %= nums[i];
    }

    cout << answer;
}