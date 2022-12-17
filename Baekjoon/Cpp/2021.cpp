#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

typedef pair<int, int> pii;

vector<int> map[200001];
int visited[200001];

int main() {
    int n, l;
    cin >> n >> l;

    for (int i = 1; i <= l; i++) {
        while (true) {
            int input;
            cin >> input;

            if (input == -1) {
                break;
            }

            map[input].push_back(i + 100000);
            map[i + 100000].push_back(input);
        }
    }

    int b, e;
    cin >> b >> e;

    fill_n(visited, 200001, -1);

    queue<pii> q;
    q.push({ b,-1 });
    int answer = -1;
    while (!q.empty()) {
        int nd = q.front().first;
        int dist = q.front().second;
        q.pop();

        for (int& i: map[nd]) {
            if (visited[i] > -1) {
                continue;
            }

            if (i > 100000) {
                q.push({ i,dist + 1 });
                visited[i] = dist + 1;
            }
            else if (i == e) {
                cout << dist;
                return 0;
            }
            else {
                q.push({ i,dist });
                visited[i] = dist;
            }
        }
    }

    cout << answer;
}