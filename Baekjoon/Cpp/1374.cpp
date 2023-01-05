#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <functional>

using namespace std;

typedef pair<int, int> pii;

int main() {
    int n;
    cin >> n;

    vector<pii> arr;
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        arr.push_back({ b,c });
    }

    sort(arr.begin(), arr.end());

    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++) {
        while (!pq.empty() && pq.top() <= arr[i].first) {
            pq.pop();
        }

        pq.push(arr[i].second);

        answer = max(answer, (int)pq.size());
    }

    cout << answer;
}