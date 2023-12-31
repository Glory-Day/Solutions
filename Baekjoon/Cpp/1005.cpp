#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> map[1001];
int arr[1001], cache[1001], cnts[1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i <= 1000; i++) {
            map[i].clear();
        }

        fill(arr, arr + 1001, 0);
        fill(cache, cache + 1001, 0);
        fill(cnts, cnts + 1001, 0);

        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
        }

        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            map[a].push_back(b);
            cnts[b]++;
        }

        queue<int> q;
        for (int i = 1; i <= n; i++) {
            if (!cnts[i]) q.push(i);
            cache[i] = arr[i];
        }

        int w;
        cin >> w;

        while (!q.empty()) {
            int nd = q.front();
            q.pop();

            for (int i = 0; i < map[nd].size(); i++) {
                int nnd = map[nd][i];
                cnts[nnd]--;

                cache[nnd] = max(cache[nnd], cache[nd] + arr[nnd]);

                if (!cnts[nnd]) q.push(nnd);
            }
        }

        cout << cache[w] << '\n';
    }
}