#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <algorithm>
#include <functional>
#include <utility>

using namespace std;

typedef pair<int, int> pii;

int main() {
    int n;
    cin >> n;

    deque<pii> arr;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        arr.push_back({ a,b });
    }

    sort(arr.begin(), arr.end());

    priority_queue<int, vector<int>, greater<int>> pq;
    while (!arr.empty()) {
        auto np = arr.front();
        arr.pop_front();

        if (pq.empty()) {
            pq.push(np.second);
        }
        else {
            if (np.first >= pq.top()) {
                pq.pop();
                pq.push(np.second);
            }
            else {
                pq.push(np.second);
            }
        }
    }

    cout << pq.size();
}