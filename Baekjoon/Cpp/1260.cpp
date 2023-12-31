#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> map[1001];
bool visited[1001];

void dfs(int n) {
    if (visited[n]) return;

    visited[n] = true;
    cout << n << ' ';

    for (int& i: map[n]) {
        dfs(i);
    }
}

void bfs(int n) {
    queue<int> q;
    q.push(n);

    while(!q.empty()) {
        int idx = q.front();
        q.pop();

        if (visited[idx]) continue;

        visited[idx] = true;
        cout << idx << ' ';

        for (int& i: map[idx]) {
            q.push(i);
        }
    }
}

int main() {
    int n, m, b;
    cin >> n >> m >> b;

    for (int i = 0; i < m; i++) {
        int input1, input2;
        cin >> input1 >> input2;
        map[input1].push_back(input2);
        map[input2].push_back(input1);
    }

    for (vector<int> &i: map) {
        sort(i.begin(), i.end());
    }

    dfs(b);

    cout << '\n';
    fill(visited, visited + 1001, false);

    bfs(b);
}