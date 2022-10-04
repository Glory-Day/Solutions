#include <iostream>
#include <climits>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

vector<pii> map[1001];
int visited[1001];

int dijkstra(int b, int e, int n) {
    vector<int> nds(n + 1, INT_MAX);
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
                visited[nnd] = nd;
                pq.push({ -ncst,nnd });
            }
        }
    }

    return nds[e];
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        map[a].push_back({ b,c });
    }

    int b, e;
    cin >> b >> e;

    int answer = dijkstra(b, e, n);

    int nd = e;
    vector<int> nds;
    while (nd != b) {
        nds.push_back(nd);
        nd = visited[nd];
    }
    nds.push_back(nd);

    cout << answer << '\n';
    cout << nds.size() << '\n';
    for (auto it = nds.rbegin(); it != nds.rend(); it++) {
        cout << *it << ' ';
    }
}