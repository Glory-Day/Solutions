#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

typedef pair<int, int> pii;

vector<pii> map[10001];
bool visited[10001];

pii bfs(int n) {
    pii answer = { 0,0 };

    queue<pii> q;
    q.push({ n,0 });

    visited[n] = true;

    while (!q.empty()) {
        int nd = q.front().first;
        int cst = q.front().second;
        q.pop();

        for (auto& i: map[nd]) {
            int nnd = i.first;
            int ncst = cst + i.second;

            if (visited[nnd]) continue;

            visited[nnd] = true;
            if (answer.second < ncst) {
                answer = { nnd,ncst };
            }

            q.push({ nnd,ncst });
        }
    }

    return answer;
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        map[a].push_back({ b,c });
        map[b].push_back({ a,c });
    }

    pii nd = bfs(1);
    fill(visited, visited + 10001, false);
    pii answer = bfs(nd.first);

    cout << answer.second;
}