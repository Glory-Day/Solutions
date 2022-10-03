#include <iostream>
#include <vector>
#include <utility>

using namespace std;

typedef pair<int, int> pii;

typedef struct _edge {
    int a, b, c;
} edge;

vector<edge> edges;
vector<int> map[1001];
vector<int> answer;

void dfs(int nd) {
    while (!map[nd].empty()) {
        int adj = map[nd].back();
        if (edges[adj].c) {
            edges[adj].c--;
            dfs(edges[adj].a + edges[adj].b - nd);
        }
        else map[nd].pop_back();
    }

    answer.push_back(nd);
}

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        for (int j = 1; j <= n; j++) {
            int input;
            cin >> input;

            if (i <= j && input) {
                edges.push_back({ i,j,input });
                map[i].push_back(edges.size() - 1);
                map[j].push_back(edges.size() - 1);
            }

            cnt += input;
        }

        if (cnt % 2) {
            cout << -1;
            return 0;
        }
    }

    dfs(1);

    for (auto& i: answer) cout << i << " ";
}