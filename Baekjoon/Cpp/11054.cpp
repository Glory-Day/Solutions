#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;

int nums[1001];
int cache[1001];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
    }

    int len = 0;
    vector<int> v;
    for (int i = 1; i <= n; i++) {
        auto it = lower_bound(cache + 1, cache + len + 1, nums[i]);
        *it = nums[i];
        v.push_back(it - cache);
        if (it == cache + len + 1) {
            len++;
        }
    }

    reverse(nums + 1, nums + n + 1);
    memset(cache + 1, 0, n * sizeof(int));

    len = 0;
    for (int i = 1; i <= n; i++) {
        auto it = lower_bound(cache + 1, cache + len + 1, nums[i]);
        *it = nums[i];
        v[n - i] += (it - cache);
        if (it == cache + len + 1) {
            len++;
        }
    }

    int mx = 0;
    for (int& i: v) {
        mx = max(mx, i);
    }

    cout << mx - 1;
}