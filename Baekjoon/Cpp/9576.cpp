#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

bool visited[1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    priority_queue<pii> pq;
    while (t--) {
        int n, m;
        cin >> n >> m;

        fill(visited, visited + n, false);

        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            pq.push({ -b,-a });            
        }

        int answer = 0;
        while (!pq.empty()) {
            int b = -pq.top().first;
            int a = -pq.top().second;
            pq.pop();

            for (int i = a; i <= b; i++) {
                if (!visited[i]) {
                    visited[i] = true;
                    answer++;
                    break;
                }
            }
        }

        cout << answer << '\n';
    }
}