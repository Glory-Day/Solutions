#include <iostream>
#include <climits>
#include <algorithm>
#include <utility>
#include <memory.h>

using namespace std;

typedef pair<int, int> pii;

pii directions[4] = { { 1,0 },{ -1,0 },{ 0,1 },{ 0,-1 } };

char map[10][10];

int main() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> map[i][j];
        }
    }

    char copy[10][10];
    auto flip = [&](int y, int x) {
        copy[y][x] = (copy[y][x] == 'O') ? '#' : 'O';
        for (auto& d: directions) {
            int ny = y + d.first;
            int nx = x + d.second;
            if (0 <= ny && ny < 10 && 0 <= nx && nx < 10) {
                copy[ny][nx] = (copy[ny][nx] == 'O') ? '#' : 'O';
            }
        }
    };

    int answer = INT_MAX;
    int n = (1 << 10) - 1;
    for (int i = n; true; i = ((i - 1) & n)) {        
        memcpy(copy, map, sizeof(map));

        int tmp = 0;
        for (int j = 0; j < 10; j++) {
            if ((i | (1 << j)) == i) {
                flip(0, j);
                tmp++;
            }
        }

        for (int j = 1; j < 10; j++) {
            for (int k = 0; k < 10; k++) {
                if (copy[j - 1][k] == 'O') {
                    flip(j, k);
                    tmp++;
                }
            }
        }

        bool chk = true;
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < 10; k++) {
                if (copy[j][k] == 'O') {
                    chk = false;
                }
            }
        }

        if (chk) {
            answer = min(answer, tmp);
        }

        if (i == 0) {
            break;
        }
    }

    if (answer == INT_MAX) {
        cout << -1;
    }
    else {
        cout << answer;
    }
}