#include <iostream>
#include <vector>

using namespace std;

vector<int> map[101];
bool visited[101];

int dfs(int n) {
    int sum = 0;

    if (visited[n]) return sum;

    sum = 1;
    visited[n] = true;

    for (int& i: map[n]) {
        sum += dfs(i);
    }

    return sum;
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

    cout << dfs(1) - 1;
}