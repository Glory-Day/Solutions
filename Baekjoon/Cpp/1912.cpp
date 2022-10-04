#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

int nums[100001];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int mx = INT_MIN, here = 0;

    for (int i = 0; i < n; i++) {
        here = here + nums[i];
        if (mx < here) mx = here;
        if (here < 0) here = 0;
    }

    cout << mx;
}