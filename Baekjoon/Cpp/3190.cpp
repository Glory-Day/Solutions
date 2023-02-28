#include <iostream>
#include <queue>
#include <utility>

using namespace std;

typedef pair<int, int> pii;

pii directions[4] = {{ 0,1 },{ 1,0 },{ 0,-1 },{ -1,0 }};

int main() {
    int n, k;
    cin >> n >> k;

    int map[101][101];
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        map[a - 1][b - 1] = 1;
    }

    int l;
    cin >> l;

    vector<pair<int, char>> arr;
    for (int i = 0; i < l; i++) {
        int a;
        char b;
        cin >> a >> b;
        arr.push_back({ a,b });
    }

    
    queue<pii> q;
    vector<vector<bool>> visited(101, vector<bool>(101, false));
    q.push({ 0,0 });
    visited[0][0] = true;

    int answer = 0;
    int x = 0, y = 0;
    int i = 0, j = 0;
    while (true) {
        int nx = x + directions[i].first;
        int ny = y + directions[i].second;
        answer++;

        if (nx < 0 || ny < 0 || nx >= n || ny >= n || visited[nx][ny]) {
            break;
        }

        x = nx;
        y = ny;
        visited[nx][ny] = true;
        q.push({ nx,ny });
        if (map[nx][ny]) {
            map[nx][ny] = 0;
        }
        else {
            visited[q.front().first][q.front().second] = false;
            q.pop();
        }

        if (answer == arr[j].first) {
            if (arr[j].second == 'D') {
                i = (i + 1 > 3) ? 0 : i + 1;
            }
            else {
                i = (i - 1 < 0) ? 3 : i - 1;
            }

            j++;
        }
    }

    cout << answer;
}