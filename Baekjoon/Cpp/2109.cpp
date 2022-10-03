#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
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
        arr.push_back({ b,a });
    }

    sort(arr.begin(), arr.end());

    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++) {
        pq.push(arr[i].second);
        answer += arr[i].second;

        if (pq.size() > arr[i].first) {
            answer -= pq.top();
            pq.pop();
        }
    }

    cout << answer;
}