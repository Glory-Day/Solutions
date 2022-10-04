#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>

using namespace std;

typedef pair<int, int> pii;

pii direction[4] = { { -1,0 },{ 1,0 },{ 0,-1 },{ 0,1 } };

bool map[25][25];

bool check(int y, int x) {
    return 0 <= y && y < 25 && 0 <= x && x < 25;
}

int dfs(int y, int x) {
    int sum = 1;

    map[y][x] = false;

    for (auto i: direction) {
        int ny = y + i.first;
        int nx = x + i.second;

        if (check(ny, nx) && map[ny][nx]) {
            sum += dfs(ny, nx);
        }
    }

    return sum;
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string input;
        cin >> input;
        for (int j = 0; j < input.size(); j++) {
            map[i][j] = input[j] - '0';
        }
    }

    vector<int> answer;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (map[i][j]) {
                answer.push_back(dfs(i, j));
            }
        }
    }

    cout << answer.size() << '\n';

    sort(answer.begin(), answer.end());

    for (int& i: answer) {
        cout << i << '\n';
    }
}