#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <utility>

using namespace std;

typedef pair<int, int> pii;

unordered_map<int, vector<pii>> mp;
bool visited[100001];
int mxnd, mxd;

void dfs(int nd, int d) {
    if (visited[nd]) return;

    if (mxd < d) {
        mxnd = nd;
        mxd = d;
    }

    visited[nd] = true;
    for (auto& i: mp[nd]) {
        dfs(i.first, d + i.second);
    }
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int nd;
        cin >> nd;

        int a, b;
        while (true) {
            cin >> a;
            if (a == -1) break;
            cin >> b;
            mp[nd].push_back({ a,b });
        }
    }

    dfs(1, 0);
    fill(visited, visited + 100001, false);

    mxd = 0;
    dfs(mxnd, 0);

    int answer = mxd;

    cout << answer;
}    