#include <iostream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

typedef pair<int ,int> pii;

int map[9][9];
bool rows[9][9], columns[9][9], boxes[9][9];
vector<pii> v;
int len;

void print() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << map[i][j];
        }
        cout << '\n';
    }
}

void f(int lv) {
    if (lv == len) {
        print();
        exit(0);
    }

    for (int i = 1; i <= 9; i++) {
        int x = v[lv].first;
        int y = v[lv].second;
        
        if (!rows[x][i] && !columns[y][i] && !boxes[(x / 3) * 3 + (y / 3)][i]) {
            rows[x][i] = columns[y][i] = true;
            boxes[(x / 3) * 3 + (y / 3)][i] = true;
            map[x][y] = i;

            f(lv + 1);

            rows[x][i] = columns[y][i] = false;
            boxes[(x / 3) * 3 + (y / 3)][i] = false;
            map[x][y] = 0;
        }
    }
}

int main() {
    for (int i = 0; i < 9; i++) {
        string input;
        cin >> input;

        for (int j = 0; j < 9; j++) {
            int tmp = input[j] - '0';
            if (tmp != 0) {
                rows[i][tmp] = true;
                columns[j][tmp] = true;
                boxes[(i / 3) * 3 + (j / 3)][tmp] = tmp;
            }
            else {
                v.push_back({ i,j });
            }

            map[i][j] = tmp;
        }
    }

    len = v.size();

    f(0);
}