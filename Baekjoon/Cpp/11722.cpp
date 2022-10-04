#include <iostream>
#include <algorithm>

using namespace std;

int nums[1001];
int cache[1001];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
    }

    reverse(nums + 1, nums + n + 1);

    int len = 0;
    for (int i = 1; i <= n; i++) {
        auto it = lower_bound(cache + 1, cache + len + 1, nums[i]);
        *it = nums[i];
        if (it == cache + len + 1) {
            len++;
        }
    }

    cout << len;
}