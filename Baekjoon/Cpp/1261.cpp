#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> pipii;

int main() {
    int n, m;
    cin >> m >> n;

    vector<vector<int>> map;
    vector<vector<int>> answer;
    for (int i = 0; i < n; i++) {
        vector<int> inputs;
        vector<int> tmp;
        string input;
        cin >> input;

        for (int j = 0; j < m; j++) {
            inputs.push_back(input[j] - '0');
            tmp.push_back(10000);
        }

        map.push_back(inputs);
        answer.push_back(tmp);
    }

    pii directions[4] = { { -1,0 },{ 1,0 },{ 0,-1 },{ 0,1 } };
    auto dijkstra = [&]() {
        priority_queue<pipii> pq;
        pq.push({ 0,{ 0,0 } });
        answer[0][0] = 0;

        while (!pq.empty()) {
            int cst = -pq.top().first;
            int y = pq.top().second.first;
            int x = pq.top().second.second;
            pq.pop();

            for (auto& i: directions) {
                int ny = y + i.first;
                int nx = x + i.second;

                if (0 <= ny && ny < n && 0 <= nx && nx < m) {
                    if (answer[ny][nx] > answer[y][x] + map[ny][nx]) {
                        answer[ny][nx] = answer[y][x] + map[ny][nx];
                        pq.push({ -answer[ny][nx],{ ny,nx } });
                    }
                }
            }
        }
    };

    dijkstra();

    cout << answer[n - 1][m - 1];
}