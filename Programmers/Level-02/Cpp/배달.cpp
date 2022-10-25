#include <iostream>
#include <climits>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

typedef pair<int, int> pii;

int solution(int n, vector<vector<int>> road, int k) {
    int answer = 0;

    vector<vector<pii>> map(n + 1);
    for (int i = 0; i < road.size(); i++) {
        map[road[i][0]].push_back({ road[i][1],road[i][2] });
        map[road[i][1]].push_back({ road[i][0],road[i][2] });
    }

    vector<int> visited(n + 1, INT_MAX);
    visited[1] = 0;

    priority_queue<pii> pq;
    pq.push({ 0,1 });

    while (!pq.empty()) {
        int cst = -pq.top().first;
        int nd = pq.top().second;
        pq.pop();

        if (visited[nd] < cst) {
            continue;
        }

        for (int i = 0; i < map[nd].size(); i++) {
            int nnd = map[nd][i].first;
            int ncst = cst + map[nd][i].second;

            if (visited[nnd] > ncst) {
                visited[nnd] = ncst;
                pq.push({ -ncst,nnd });
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (visited[i] <= k) {
            answer++;
        }
    }

    return answer;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> road;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        road.push_back({ a,b,c });
    }

    int k;
    cin >> k;

    int answer = solution(n, road, k);

    cout << answer;
}