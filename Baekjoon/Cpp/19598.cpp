#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <functional>

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

    sort(arr.begin(), arr.end());

    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(arr.front().second);

    int answer = 1;
    for (int i = 1; i < n; i++) {
        while (!pq.empty() && pq.top() <= arr[i].first) {
            pq.pop();
        }

        pq.push(arr[i].second);
        answer = max(answer, (int)pq.size());
    }

    cout << answer;
}