#include <iostream>
#include <climits>
#include <vector>
#include <utility>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

vector<pii> map[501];

vector<ll> bf(int v) {
    vector<ll> nds(v + 1, INT_MAX);
    nds[1] = 0;

    bool check = true;
    for (int i = 1; i <= v; i++) {
        for (int j = 1; j <= v; j++) {
            for (auto k: map[j]) {
                int nd = k.first;
                int cst = k.second;

                if (nds[j] != INT_MAX && nds[nd] > nds[j] + cst) {
                    nds[nd] = nds[j] + cst;
                    if (i == v) {
                        check = false;
                        break;
                    }
                }
            }
        }
    }

    if (!check) {
        nds.clear();
        return nds;
    }

    return nds;
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        map[a].push_back({ b,c });
    }

    vector<ll> answer = bf(n);

    if (answer.empty()) {
        cout << -1 << '\n';
    }
    else {
        for (int i = 2; i <= n; i++) {
            if (answer[i] == INT_MAX) cout << -1 << '\n';
            else cout << answer[i] << '\n';
        }
    }
}