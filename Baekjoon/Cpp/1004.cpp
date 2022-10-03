#include <iostream>
#include <vector>
#include <utility>

using namespace std;

typedef pair<int, int> pii;

int main() {
    int t;
    cin >> t;

    while (t--) {
        pii b, e;
        cin >> b.first >> b.second >> e.first >> e.second;

        int n;
        cin >> n;

        int answer = 0;
        for (int i = 0; i < n; i++) {
            int x, y, r;
            cin >> x >> y >> r;

            r *= r;
            int d1 = (b.first - x) * (b.first - x) + (b.second - y) * (b.second - y);
            int d2 = (e.first - x) * (e.first - x) + (e.second - y) * (e.second - y);

            if (d1 < r && d2 < r) continue;
            else if (d1 < r || d2 < r) answer++;
        }

        cout << answer << '\n';
    }
}