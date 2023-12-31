#include <iostream>
#include <climits>
#include <vector>
#include <set>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

pii direction[8] = { { -1,0 },{ -1,-1 },{ 0,-1 },{ 1,-1 },{ 1,0 },{ 1,1 },{ 0,1 },{ -1,1 } };

int n;
int map[51][51];
bool visited[51][51];
vector<pii> dest;

bool check(int y, int x) {
	return y >= 0 && y < n && x >= 0 && x < n;
}

bool isPossible() {
    int cnt = 0;

    for (pii& i: dest) {
        if (visited[i.first][i.second]) cnt++;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            visited[i][j] = false;
        }
    }

    return cnt == dest.size();
}

void dfs(int y, int x, int b, int e) {
    if (check(y, x) && !visited[y][x] && b <= map[y][x] && map[y][x] <= e) {
        visited[y][x] = true;

        for (pii& i: direction) {
            int ny = y + i.first;
            int nx = x + i.second;

            dfs(ny, nx, b, e);
        }
    }
}

int main() {
    cin >> n;

    int y, x;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char c;
            cin >> c;

            if (c == 'P') y = i, x = j;
            else if (c == 'K') dest.push_back({ i,j });
        }
    }

    set<int> st;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
            st.insert(map[i][j]);
        }
    }

    int answer = INT_MAX;
    auto b = st.begin(), e = st.begin();
    while (e != st.end()) {
        while (b != st.end()) {
            dfs(y, x, *b, *e);

            if (!isPossible()) break;

            answer = min(answer, *e - *b);
            b++;
        }

        e++;
    }

    cout << answer;
}