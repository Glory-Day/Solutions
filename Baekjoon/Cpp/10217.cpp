#include <iostream>
#include <climits>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

typedef pair<pair<int, int>, int> ppiii;
typedef pair<int, int> pii;

vector<ppiii> map[101];

int dijkstra(int b, int n, int m) {
    priority_queue<ppiii> pq;
    pq.push({ { 0,0 },b });

    vector<vector<int>> nds(n + 1, vector<int>(m + 1, INT_MAX));
    nds[b][0] = 0;

    while (!pq.empty()) {
        int dist = -pq.top().first.first;
        int cst = -pq.top().first.second;
        int nd = pq.top().second;
        pq.pop();

        if (nds[nd][cst] < dist || cst > m) continue;

        if (nd == n) return dist;

        for (auto i: map[nd]) {
            int ndist = i.first.first + dist;
            int ncst = i.first.second + cst;
            int nnd = i.second;

            if (ncst > m) continue;

            if (ndist < nds[nnd][ncst]) {
                nds[nnd][ncst] = ndist;
                pq.push({ {-ndist,-ncst},nnd });
            }
        }
    }

    return -1;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;

        for (int i = 0; i <= 100; i++) {
            map[i].clear();
        }

        for (int i = 0; i < k; i++) {
            int a, b, c, d;
            cin >> a >> b >> c >> d;
            map[a].push_back({ { d,c },b });
        }

        int answer = dijkstra(1, n, m);

        if (n == 1) {
            cout << 0 << '\n';
        }
        else if (k == 0 || answer == -1) {
            cout << "Poor KCM\n";
        }
        else {
            cout << answer << '\n';
        }
    }
}