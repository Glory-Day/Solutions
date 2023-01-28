#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

using ll = long long;

int main() {
    int n, k;
    cin >> n >> k;

    vector<ll> arr;
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    for (int i = 0; i < n; i++) {
        ll input;
        cin >> input;
        arr.push_back(input);
        pq.push(input);
    }

    ll answer = 0;
    for (int i = 0; i < k; i++) {
        answer = pq.top();
        pq.pop();

        for (int j = 0; j < n; j++) {
            pq.push(answer * arr[j]);

            if (answer % arr[j] == 0) {
                break;
            }
        }
    }

    cout << answer;
}