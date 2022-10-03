#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <functional>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

/*
    문제 설명: 체스판에 숫자들이 적어져 있다. 
    비숍을 임의의 위치에 놓았을 때 비숍의 이동경로에 있는 숫자들의 최대합을 출력한다.

    풀이: 비숍은 대각선 네방향으로 움직인다. 따라서 좌표를 네방향으로 움직일 수 있게 좌표를 수정하는 배열을 생성한다.
    한 좌표를 정하면 주어진 방향대로 움직이면서 체스판에 적어진 숫자를 더해 한 좌표에 대한 총합을 구한다.
    이 과정를 체스판의 모든 좌표에 수행하면서 최대합을 구한다.
*/

int n, m;
int map[201][201];

pii directions[4] = { { 1,1 },{ -1,-1 },{ 1,-1 },{ -1,1 } };

bool check(int y, int x) {
    return (0 <= y && y < n) && (0 <= x && x < m);
}

int f(int y, int x) {
    int sum = map[y][x];

    pii d[4] = { {y,x},{y,x},{y,x},{y,x} };
    while (true) {
        int chk = 0;
        for (int i = 0; i < 4; i++) {
            d[i].first += directions[i].first;
            d[i].second += directions[i].second;

            if (check(d[i].first, d[i].second)) {
                sum += map[d[i].first][d[i].second];
            }
            else {
                chk++;
            }
        }

        if (chk == 4) break;
    }

    return sum;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> map[i][j];
            }
        }

        int answer = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                answer = max(answer, f(i, j));
            }
        }

        cout << answer << '\n';
    }
}