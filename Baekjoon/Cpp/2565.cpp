#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

typedef pair<int, int> pii;

pii arr[101];
int cache[101];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }

    sort(arr + 1, arr + n + 1);

    int len = 0;
    for (int i = 1; i <= n; i++) {
        auto it = lower_bound(cache + 1, cache + len + 1, arr[i].second);
        *it = arr[i].second;
        if (it == cache + len + 1) {
            len++;
        }
    }

    cout << n - len;
}