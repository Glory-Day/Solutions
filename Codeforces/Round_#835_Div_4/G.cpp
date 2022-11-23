#include <iostream>
#include <set>
#include <vector>
#include <utility>

using namespace std;

typedef pair<int, int> pii;

int n, a, b;

set<int> st;
vector<pii> map[100001];

void dfs1(int u, int p, int x) {
    if (u == b) {
        return;
    }

    st.insert(x);

    for (auto i: map[u]) {
        int v = i.first, w = i.second;
        
        if (v != p) {
            dfs1(v, u, x ^ w);
        }
    }
}

bool dfs2(int u, int p, int x) {
    if (u != b && st.count(x)) {
        return true;
    }

    for (auto i: map[u]) {
        int v = i.first, w = i.second;

        if (v != p) {
            if (dfs2(v, u, w ^ x)) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        cin >> n >> a >> b;
        --a, --b;

        for (int i = 0; i < n; i++) {
            map[i].clear();
        }
        st.clear();

        for (int i = 0; i < n - 1; i++) {
            int u, v, w;
            cin >> u >> v >> w;

            --u, --v;
            map[u].push_back({ v,w });
            map[v].push_back({ u,w });
        }

        dfs1(a, -1, 0);
        
        if (dfs2(b, -1, 0)) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
}