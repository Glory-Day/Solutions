#include <iostream>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

typedef long long ll;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        priority_queue<ll, vector<ll>, greater<ll>> pq;
        for (int i = 0; i < n; i++) {
            int input;
            cin >> input;
            pq.push(input);
        }

        ll answer = 0;
        for (int i = 0; i < n - 1; i++) {
            ll tmp = pq.top();
            pq.pop();
            tmp += pq.top();
            pq.pop();
            pq.push(tmp);
            answer += tmp;
        }

        cout << answer << '\n';
    }
}