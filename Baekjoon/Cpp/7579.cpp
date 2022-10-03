#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

typedef pair<int, int> pii;

pii arr[101];
int cache[10001];

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> arr[i].first;
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i].second;
        sum += arr[i].second;
    }

    for (int i = 0; i < n; i++) {
        for (int j = sum; j >= arr[i].second; j--) {
            cache[j] = max(cache[j], cache[j - arr[i].second] + arr[i].first);
        }
    }

    int i = 0;
    for (i = 0; i < sum, cache[i] < m; i++);
    cout << i;
}