#include <iostream>
#include <climits>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX 987654321

using namespace std;

typedef pair<int, int> pii;

vector<pii> map[801];

vector<int> dijkstra(int b, int v) {
    vector<int> nds(v + 1, MAX);
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
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        map[a].push_back({ b,c });
        map[b].push_back({ a,c });
    }

    int a, b;
    cin >> a >> b;

    vector<int> d1 = dijkstra(1, n);
    vector<int> d2 = dijkstra(a, n);
    vector<int> d3 = dijkstra(b, n);

    int answer = min(d1[a] + d2[b] + d3[n], d1[b] + d2[n] + d3[a]);

    if (answer >= MAX || answer < 0) {
        cout << -1 << '\n';
    }
    else {
        cout << answer << '\n';
    }
}