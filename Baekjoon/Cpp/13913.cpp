#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int n, m;
int map[100001];
int visited[100001];

bool check(int x) {
    return 0 <= x && x <= 100000;
}

void bfs() {
    queue<int> q;
    q.push(n);
    map[n] = 0;
    visited[n] = true;

    vector<int> ts;
    while (!q.empty()) {
        int x = q.front();
        q.pop();

        if (x == m) break;

        for (int i = 0; i < 3; i++) {
            int nx = x;

            switch (i) {
                case 0: nx++; break;
                case 1: nx--; break;
                case 2: nx *= 2; break;
            }

            if (check(nx) && !map[nx]) {
                map[nx] = map[x] + 1;
                visited[nx] = x;
                q.push(nx);
            }
        }
    }
}

int main() {
    cin >> n >> m;

    bfs();

    cout << map[m] << '\n';

    vector<int> answer;
    while (m != n) {
        answer.push_back(m);
        m = visited[m];
    }
    answer.push_back(m);

    for (auto it = answer.rbegin(); it != answer.rend(); it++) {
        cout << *it << ' ';
    }
}