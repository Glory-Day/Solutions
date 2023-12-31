#include <iostream>
#include <climits>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

#define MAX 50001

typedef long long ll;

typedef struct _Node {
    int node;
    ll first, second;

    bool operator<(const _Node a) const {
        if (this->first == a.first) return this->second < a.second;
        return this->first > a.first;
    }

} Node;

typedef struct _Cost {
    ll first, second;

    bool operator<(const _Cost a) const {
        if (this->first == a.first) return this->second < a.second;
        return this->first < a.first;
    }

} Cost;

int n, m;
vector<Node> map[MAX];
priority_queue<Cost> costs[MAX];

void dijkstra() {
    priority_queue<Node> pq;
    pq.push({ 1,0 });
    costs[1].push({ 0,0 });

    while (!pq.empty()) {
        int nd = pq.top().node;
        ll cst1 = pq.top().first;
        ll cst2 = pq.top().second;
        pq.pop();

        for (auto i: map[nd]) {
            int nnd = i.node;

            if (costs[nnd].size() < 2) {
                costs[nnd].push({ (ll)(cst1 + i.first),(ll)(cst2 + i.second) });
                pq.push({ nnd,(ll)(cst1 + i.first),(ll)(cst2 + i.second) });
            }
            else if (costs[nnd].top().first > (ll)(cst1 + i.first)) {
                costs[nnd].pop();
                costs[nnd].push({ (ll)(cst1 + i.first),(ll)(cst2 + i.second) });
                pq.push({ nnd,(ll)(cst1 + i.first),(ll)(cst2 + i.second) });
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int tc;
    cin >> tc;

    for (int t = 1; t <= tc; t++) {
        for (int i = 0; i < MAX; i++) {
            map[i].clear();
            while (!costs[i].empty()) costs[i].pop();
        }

        cin >> n >> m;

        for (int i = 0; i < m; i++) {
            int a, b, c, d;
            cin >> a >> b >> c >> d;
            map[a].push_back({ b,c,d });
            map[b].push_back({ a,c,d });
        }

        dijkstra();

        cout << "Game #" << t << ": Suckzoo ends game in time " << costs[n].top().first << ", earning "
         << costs[n].top().second << " garnet(s).\n";
    }
}