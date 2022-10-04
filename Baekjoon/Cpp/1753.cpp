#include <iostream>
#include <climits>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

vector<pii> map[20001];

vector<int> dijkstra(int b, int v) {
    vector<int> nds(v + 1, INT_MAX);
    nds[b] = 0;

    priority_queue<pii> pq;
    pq.push({ 0,b });

    while (!pq.empty()) {
        int cst = -pq.top().first;
        int nd = pq.top().second;
        pq.pop();

        if (nds[nd] < cst) continue;

        for (auto i: map[nd]) {
            int nnd = i.first;
            int ncst = cst + i.second;

            if (nds[nnd] > ncst) {
                nds[nnd] = ncst;
                pq.push({ -ncst,nnd });
            }
        }
    }

    return nds;
}

int main() {
    int n, m, s;
    cin >> n >> m >> s;

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        map[a].push_back({ b,c });
    }

    vector<int> answer = dijkstra(s, n);

    for (int i = 1; i <= n; i++) {
        if (answer[i] == INT_MAX) {
            cout << "INF" << '\n';
        }
        else {
            cout << answer[i] << '\n';
        }
    }
}