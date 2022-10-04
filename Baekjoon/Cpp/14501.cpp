#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

pii arr[16];
int cache[16];

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }

    for (int i = n; i >= 1; i--) {
        if (arr[i].first <= n - i + 1) {
            int mx = 0;
            for (int j = i + arr[i].first; j <= n; j++) {
                mx = max(mx, cache[j]);
            }
            cache[i] = arr[i].second + mx;
        }
    }

    int answer = -1;
    for (int i = 1; i <= n; i++) {
        answer = max(answer, cache[i]);
    }

    cout << answer;
}