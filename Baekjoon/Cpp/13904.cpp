#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

typedef pair<int, int> pii;

bool cmpA(pii &a, pii &b) {
    if (a.first == b.first) {
        return a.second > b.second;
    }
    
    return a.first < b.first;
}

struct cmpB {
    bool operator()(pii &a, pii &b) {
        if (a.second == b.second) {
            return a.first > b.first;
        }
    
        return a.second > b.second;
    }
};

int main() {
    int n;
    cin >> n;

    int mx = 0;
    vector<pii> arr;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        arr.push_back({ a,b });
        mx = max(mx, a);
    }

    sort(arr.begin(), arr.end(), cmpA);

    priority_queue<pii, vector<pii>, cmpB> pq;
    int answer = 0, tmp = 1;
    for (int i = 0; i < n; i++) {
        while (!pq.empty() && arr[i].first < tmp) {
            if (pq.top().second > arr[i].second) break;

            answer -= pq.top().second;
            pq.pop();
            tmp--;
        }

        if (arr[i].first >= tmp) {
            answer += arr[i].second;
            pq.push(arr[i]);
            tmp++;
        }
    }

    cout << answer;
}