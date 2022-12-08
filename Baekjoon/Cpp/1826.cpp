#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

typedef pair<int, int> pii;

int main() {
    int n;
    cin >> n;

    vector<pii> arr;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        arr.push_back({ a,b });
    }

    int l, p;
    cin >> l >> p;

    sort(arr.begin(), arr.end());

    int i = 0;
    int answer = 0;
    priority_queue<int> pq;
    while (p < l) {
        while (i < n && p >= arr[i].first) {
            pq.push(arr[i++].second);
        }

        if (pq.empty()) {
            answer = -1;
            break;
        }

        p += pq.top();
        pq.pop();
        answer++;
    }

    cout << answer;
}