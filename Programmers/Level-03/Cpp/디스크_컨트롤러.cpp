#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int solution(vector<vector<int>> jobs) {
    int answer = 0;

    priority_queue<pii> pq;
    sort(jobs.begin(), jobs.end());

    for (int i = 0, j = 0; i < jobs.size() || !pq.empty();) {
        if (i < jobs.size() && j >= jobs[i][0]) {
            pq.push({ -jobs[i][1],jobs[i][0] });
            i++;
            continue;
        }

        if (!pq.empty()) {
            j -= pq.top().first;
            answer += j - pq.top().second;
            pq.pop();
        }
        else {
            j = jobs[i][0];
        }
    }

    return answer / jobs.size();
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> jobs;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        jobs.push_back({ a,b });
    }

    int answer = solution(jobs);

    cout << answer;
}