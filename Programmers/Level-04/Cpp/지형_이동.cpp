#include <iostream>
#include <cmath>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

typedef struct _edge {
    int u, v, c;
    _edge(int u, int v, int c): u(u), v(v), c(c) {}
} edge;

int map[301][301];
pii directions[4] = { { 0,1 },{ 0,-1 },{ 1,0 },{ -1,0 } };
int parent[100001];

int find(int x) {
    if (parent[x] == -1) {
        return x;
    }

    return parent[x] = find(parent[x]);
}

bool isValid(int x, int y, int n) {
    return 0 <= x && x < n && 0 <= y && y < n;
}

void dfs(vector<vector<int>>& land, int x, int y, int height, int num) {
    if (map[x][y]) {
        return;
    }

    map[x][y] = num;

    for (auto& i: directions) {
        int nx = x + i.first;
        int ny = y + i.second;

        if (isValid(nx, ny, land.size()) && abs(land[nx][ny] - land[x][y]) <= height) {
            dfs(land, nx, ny, height, num);
        }
    }
}

int solution(vector<vector<int>> land, int height) {
    int answer = 0;

    int num = 1;
    int n = land.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!map[i][j]) {
                dfs(land, i, j, height, num);
                num++;
            }
        }
    }

    vector<edge> edges;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int u = map[i][j];
            for (auto& k: directions) {
                int nx = i + k.first;
                int ny = j + k.second;

                if (!isValid(nx, ny, n)) {
                    continue;
                }
                
                int v = map[nx][ny];

                if (u == v) {
                    continue;
                }

                edges.push_back({ u,v,abs(land[i][j] - land[nx][ny]) });
            }
        }
    }
    sort(edges.begin(), edges.end(), [&](const edge& a, const edge& b) { return a.c < b.c; });
    fill(parent, parent + 100000, -1);

    for (auto& edge: edges) {
        int u = find(edge.u);
        int v = find(edge.v);

        if (u == v) {
            continue;
        }

        parent[u] = v;
        answer += edge.c;
    }

    return answer;
}

int main() {
    int n, height;
    cin >> n;

    vector<vector<int>> land;
    for (int i = 0; i < n; i++) {
        vector<int> inputs;
        for (int j = 0; j < n; j++) {
            int input;
            cin >> input;
            inputs.push_back(input);
        }
        land.push_back(inputs);
    }

    cin >> height;

    int answer = solution(land, height);

    cout << answer;
}