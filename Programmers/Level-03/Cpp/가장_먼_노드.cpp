#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> map[20001];
int visited[20001];

int bfs() {
    queue<int> q;
    q.push(1);
    visited[1] = 1;

    while(!q.empty()) {
        int nd = q.front();
        q.pop();

        for (int& i: map[nd]) {
            if (!visited[i]) {
                visited[i] = visited[nd] + 1;
                q.push(i);
            }
        }
    }

    sort(visited, visited + 20001);

    int cnt = 1;
    int mx = visited[20000];
    for (int i = 20000 - 1; i >= 0; i--) {
        if (visited[i] < mx) break;
        cnt++;
    }
    return cnt;
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;

    for (vector<int>& i: edge) {
        map[i[0]].push_back(i[1]);
        map[i[1]].push_back(i[0]);
    }

    answer = bfs();

    return answer;
}

int main() {
    int n;
    cin >> n;

    int m;
    cin >> m;

    vector<vector<int>> edge;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        edge.push_back({ a,b });
    }

    int answer = solution(n, edge);

    cout << answer;
}