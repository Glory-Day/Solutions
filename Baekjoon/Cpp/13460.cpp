#include <iostream>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

typedef pair<int, int> pii;

struct point { 
    int x;
    int y;

    bool operator==(const point& other) {
        return this->x == other.x && this->y == other.y;
    }
};

const point directions[4] = { { 1,0 },{ -1,0 },{ 0,1 },{ 0,-1 } };

char matrix[10][10];
bool visited[10][10][10][10];

const vector<int> bfs(const point& a, const point& b) {
    vector<int> results;

    queue<pair<point, point>> q;
    q.push({ a,b });

    visited[a.y][a.x][b.y][b.x] = true;

    int count = 0;
    while (true) {
        if (++count > 10) break;

        int size = q.size(); 
        for (int i = 0; i < size; i++) {
            auto p = q.front();
            q.pop();

            for (int j = 0; j < 4; j++) {
                bool chk = false;
                auto na = p.first;
                auto nb = p.second;
                while (true) {
                    int nbx = nb.x + directions[j].x;
                    int nby = nb.y + directions[j].y;
                    if (matrix[nby][nbx] == '.') {
                        nb.x = nbx;
                        nb.y = nby;
                    }
                    else if (matrix[nby][nbx] == 'O') {
                        chk = true;
                        break;
                    }
                    else break;
                }

                while (true) {
                    int nax = na.x + directions[j].x;
                    int nay = na.y + directions[j].y;
                    if (matrix[nay][nax] == '.') {
                        na.x = nax;
                        na.y = nay;
                    }
                    else if (matrix[nay][nax] == 'O') {
                        if (chk == false) results.push_back(count);
                        break;
                    }
                    else break;
                }

                if (na == nb) {
                    switch (j)
                    {
                        case 0: p.first.x < p.second.x ? na.x-- : nb.x--; break;
                        case 1: p.first.x > p.second.x ? na.x++ : nb.x++; break;
                        case 2: p.first.y < p.second.y ? na.y-- : nb.y--; break;
                        case 3: p.first.y > p.second.y ? na.y++ : nb.y++; break;
                    }
                }

                if (visited[na.y][na.x][nb.y][nb.x]) continue;
                
                visited[na.y][na.x][nb.y][nb.x] = true;

                if (chk == false) q.push({ na,nb });
            }
        }
    }

    return results;
}

int main() {
    int n, m;
    cin >> n >> m;

    point a, b;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];

            switch(matrix[i][j]) {
                case 'R': a = { j,i }; break;
                case 'B': b = { j,i }; break;
            }
        }
    }

    matrix[a.y][a.x] = '.';
    matrix[b.y][b.x] = '.';

    auto results = bfs(a, b);
    if (results.empty()) {
        cout << -1;
    }
    else {
        cout << results[0];
    }
}    