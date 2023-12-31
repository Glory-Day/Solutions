#include <iostream>
#include <climits>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

#define MAX 7654321

using namespace std;

typedef pair<int, int> pii;

vector<pii> map[2002];

vector<int> dijkstra(int b, int v) {
    vector<int> nds(v + 2, MAX);
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
    int t;
    cin >> t;

    while (t--) {
        for (int i = 0; i < 2002; i++) {
            map[i].clear();
        }

        int n, m, k;
        cin >> n >> m >> k;

        int s, g, h;
        cin >> s >> g >> h;

        for (int i = 0; i < m; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            map[a].push_back({ b,c });
            map[b].push_back({ a,c });
        }

        vector<int> ts;
        for (int i = 0; i < k; i++) {
            int input;
            cin >> input;
            ts.push_back(input);
        }

        vector<int> d1 = dijkstra(s, n);
        vector<int> d2 = dijkstra(g, n);
        vector<int> d3 = dijkstra(h, n);

        vector<int> answer;
        for (int& i: ts) {
            if (d1[g] + d2[h] + d3[i] == d1[i] || d1[h] + d3[g] + d2[i] == d1[i]) {
                answer.push_back(i);
            }
        }

        sort(answer.begin(), answer.end());

        for (int& i: answer) {
            cout << i << ' ';
        }
        cout << '\n';
    }
}