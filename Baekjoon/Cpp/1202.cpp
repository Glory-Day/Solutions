#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<pii> arr;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        arr.push_back({ a,b });
    }

    vector<int> arr2;
    for (int i = 0; i < k; i++) {
        int input;
        cin >> input;
        arr2.push_back(input);
    }

    sort(arr.begin(), arr.end());
    sort(arr2.begin(), arr2.end());

    ll answer = 0;
    int j = 0;

    priority_queue<int> pq;
    for (int i = 0; i < k; i++) {
        while (arr[j].first <= arr2[i] && j < n) {
            pq.push(arr[j++].second);
        }

        if (!pq.empty()) {
            answer += pq.top();
            pq.pop();
        }
    }

    cout << answer;
}