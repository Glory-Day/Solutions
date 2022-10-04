#include <iostream>
#include <vector>
#include <queue>
#include <functional>

typedef long long ll;

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    for (int i = 0; i < n; i++) {
        ll input;
        cin >> input;
        pq.push(input);
    }

    while (m--) {
        ll a = pq.top();
        pq.pop();
        ll b = pq.top();
        pq.pop();

        pq.push(a + b);
        pq.push(a + b);
    }

    ll answer = 0;
    while (!pq.empty()) {
        answer += pq.top();
        pq.pop();
    }

    cout << answer;
}