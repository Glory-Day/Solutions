#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <functional>

using namespace std;

typedef pair<int, int> pii;

pii directions[4] = { { -1,0 },{ 1,0 },{ 0,-1 },{ 0,1 } };

int main() {
    int n;
    cin >> n;

    vector<string> map;
    for (int i = 0; i < n; i++) {
        string input;
        cin >> input;
        map.push_back(input);
    }

    pii answer = { 0,0 };

    function<int(int, int, char)> dfs1 = [&](int y, int x, char text) {
        if (text == '1' || text == '2') {
            return 0;
        }

        if (text == 'R' || text == 'G') {
            map[y][x] = '1';
        }
        else {
            map[y][x] = '2';
        }

        for (auto& d: directions) {
            int ny = y + d.first;
            int nx = x + d.second;
            if (0 <= ny && ny < n && 0 <= nx && nx < n && map[ny][nx] == text) {
                dfs1(ny, nx, map[ny][nx]);
            }
        }

        return 1;
    };
    
    function<int(int, int, char)> dfs2 = [&](int y, int x, char text) {
        if (text == '0') {
            return 0;
        }

        map[y][x] = '0';

        for (auto& d: directions) {
            int ny = y + d.first;
            int nx = x + d.second;
            if (0 <= ny && ny < n && 0 <= nx && nx < n && map[ny][nx] == text) {
                dfs2(ny, nx, map[ny][nx]);
            }
        }

        return 1;
    };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            answer.first += dfs1(i, j, map[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            answer.second += dfs2(i, j, map[i][j]);
        }
    }

    cout << answer.first << ' ' << answer.second;
}