#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int main() {
    int n, m;
    cin >> n >> m;

    int mn1 = 1001, mn2 = 1001;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        mn1 = min(mn1, a);
        mn2 = min(mn2, b);
    }

    int mn;
    mn = min(mn2 * 6, mn1);

    int answer = 0;
    while (n >= 6) {
        n -= 6;
        answer += mn;
    }

    mn = min(mn2 * n, mn1);
    answer += mn;

    cout << answer;
}