#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <functional>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
    int v, e;
    cin >> v >> e;

    vector<pii> map[10001];
    for (int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        map[a].push_back({ c,b });
        map[b].push_back({ c,a });
    }

    vector<bool> visited(10001, false);
    ll answer = 0;

    auto prim = [&]() {
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({ 0,1 });

        while (!pq.empty()) {
            pii nd = pq.top();
            pq.pop();

            if (visited[nd.second]) {
                continue;
            }

            visited[nd.second] = true;
            answer += nd.first;

            for (auto& i: map[nd.second]) {
                if (!visited[i.second]) {
                    pq.push(i);
                }
            }
        }
    };

    prim();

    cout << answer;
}