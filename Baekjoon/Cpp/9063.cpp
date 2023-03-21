#include <iostream>
#include <climits>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int main() {
    int n;
    cin >> n;

    pii mn = { INT_MAX,INT_MAX }, mx = { INT_MIN,INT_MIN };
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        mn.first = min(mn.first, a);
        mn.second = min(mn.second, b);
        mx.first = max(mx.first, a);
        mx.second = max(mx.second, b);
    }

    int answer = (mx.first - mn.first) * (mx.second - mn.second);

    cout << answer;
}