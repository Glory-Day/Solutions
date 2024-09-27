#include <iostream>
#include <climits>
#include <cmath>
#include <queue>
#include <algorithm>

using namespace std;

struct point { int x; int y;};

const point directions[4] = { { 1,0 },{ -1,0 },{ 0,1 },{ 0,-1 } };

int n, m;
char matrix[50][50];
int visited[50][50];

const bool check(const int x, const int y) {
    return 0 <= y && y < n && 0 <= x && x < m;
}

const int bfs(const int x, const int y) {
    queue<point> q;
    q.push({ x,y });

    fill_n(&visited[0][0], 50 * 50, 0);
    visited[y][x] = 1;

    int result = 0;
    while (q.empty() == false) {
        auto p = q.front();
        q.pop();

        for (auto& d: directions) {
            int nx = p.x + d.x;
            int ny = p.y + d.y;

            if (check(nx, ny) && matrix[ny][nx] == 'L' && visited[ny][nx] == 0) {
                int count = visited[p.y][p.x] + 1;
                visited[ny][nx] = count;
                result = max(result, count);

                q.push({ nx,ny });
            }
        }
    }

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    int answer = INT_MIN;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 'L') {
                int result = bfs(j, i);
                answer = max(answer, result);
            }
        }
    }

    cout << answer - 1;

    return 0;
}