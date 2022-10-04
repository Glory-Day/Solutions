#include <iostream>
#include <vector>

using namespace std;

vector<int> map[1001];
bool visited[1001];

int dfs(int n) {
    if (visited[n]) return 0;

    visited[n] = true;

    for (int& nd: map[n]) {
        dfs(nd);
    }

    return 1;
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        map[a].push_back(b);
        map[b].push_back(a);
    }

    int answer = 0;
    for (int i = 1; i <= n; i++) {
        answer += dfs(i);
    }

    cout << answer;
}