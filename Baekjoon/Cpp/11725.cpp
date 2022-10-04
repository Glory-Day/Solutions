#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> map[100001];
int visited[100001];

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        map[a].push_back(b);
        map[b].push_back(a);
    }

    queue<int> q;
    q.push(1);
    visited[1] = 1;

    while (!q.empty()) {
        int nd = q.front();
        q.pop();

        for (auto& nnd: map[nd]) {
            if (!visited[nnd]) {
                visited[nnd] = nd;
                q.push(nnd);
            }
        }
    }

    for (int i = 2; i <= n; i++) {
        cout << visited[i] << '\n';
    }
}