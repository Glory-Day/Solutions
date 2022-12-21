#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <memory.h>

using namespace std;

typedef pair<int, int> pii;

char map[2002][2002];
int visited[2002][2002];

pii directions[4] = { { 0,-1 },{ 0,1 },{ -1,0 },{ 1,0 } };

int main() {
    int n, m;
    cin >> n >> m;

    vector<pii> arr;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];

            if (map[i][j] == '.') {
                map[i][j] = '@';
            }

            if ((i == 0 || i == n - 1 || j == 0 || j == m - 1) && map[i][j] == '@') {
                arr.push_back({ i,j });
            }
        }
    }

    memset(visited, -1, sizeof(visited));

    auto check = [&n, &m](int y, int x) {
        return 0 <= y && y < n && 0 <= x && x < m;
    };

    queue<pii> q;
    q.push(arr[0]);
    while (!q.empty()) {
        pii nd = q.front();
        q.pop();

        if (nd.first == arr[1].first && nd.second == arr[1].second) {
            break;
        }

        for (int i = 0; i < 4; i++) {
            int y = nd.first + directions[i].first;
            int x = nd.second + directions[i].second;

            if (check(y, x) && map[y][x] == '@' && visited[y][x] == -1) {   
                if (i % 2 == 0) {
                    visited[y][x] = i + 1;
                }
                else {
                    visited[y][x] = i - 1;
                }

                q.push({ y,x });
            }
        }
    }

    map[arr[1].first][arr[1].second] = '.';
    while (arr[1].first != arr[0].first || arr[1].second != arr[0].second) {
        int i = visited[arr[1].first][arr[1].second];
        int y = arr[1].first + directions[i].first;
        int x = arr[1].second + directions[i].second;
        map[y][x] = '.';
        arr[1].first = y;
        arr[1].second = x;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << map[i][j];
        }
        cout << '\n';
    }
}