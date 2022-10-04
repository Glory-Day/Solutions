#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <utility>
#include <functional>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef struct _cmp {
    bool operator()(const pii& a, const pii& b) const {
        if (a.first == b.first) {
            return a.second < b.second;
        }

        return a.first > b.first;
    }
} cmp;

int main() {
    int n;
    cin >> n;

    priority_queue<pii, vector<pii>, cmp> pq1;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        pq1.push({ a,b });
    }

    int cnt = 1;
    priority_queue<int, vector<int>, greater<int>> pq2;
    while (!pq1.empty()) {
        pii tmp = pq1.top();
        pq1.pop();

        if (cnt <= tmp.first) {
            pq2.push(tmp.second);
            cnt++;
        }
        else if (pq2.top() < tmp.second) {
            pq2.pop();
            pq2.push(tmp.second);
        }
    }

    ll answer = 0;
    while (!pq2.empty()) {
        answer += pq2.top();
        pq2.pop();
    }

    cout << answer;
}