#include <iostream>
#include <vector>
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

    cout << len << '\n';

    int index = len;
    vector<int> answer;
    for (int i = v.size(); i >= 1; i--) {
        if (index == v[i - 1]) {
            answer.push_back(nums[i]);
            index--;
        }
    }

    for (int i = answer.size() - 1; i >= 0; i--) {
        cout << answer[i] << ' ';
    }
}