#include <iostream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

typedef pair<int, int> pii;

int map[101][101];

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;

    for (auto query: queries) {
        pii p = { query[0],query[1] };

        int next = map[p.first][p.second];
        int mn = map[p.first][p.second];

        while (p.second < query[3]) {
            int temp = map[p.first][p.second + 1];
            map[p.first][p.second + 1] = next;
            mn = min(mn, next);
            next = temp;
            p.second++;
        }

        while (p.first < query[2]) {
            int temp = map[p.first + 1][p.second];
            map[p.first + 1][p.second] = next;
            mn = min(mn, next);
            next = temp;
            p.first++;
        }

        while (p.second > query[1]) {
            int temp = map[p.first][p.second - 1];
            map[p.first][p.second - 1] = next;
            mn = min(mn, next);
            next = temp;
            p.second--;
        }

        while (p.first > query[0]) {
            int temp = map[p.first - 1][p.second];
            map[p.first - 1][p.second] = next;
            mn = min(mn, next);
            next = temp;
            p.first--;
        }

        answer.push_back(mn);
    }

    return answer;
}

int main() {
    int rows, columns;
    cin >> columns >> rows;

    int cnt = 1;
    for (int i = 1; i <= columns; i++) {
        for (int j = 1; j <= rows; j++) {
            map[i][j] = cnt++;
        }
    }

    int n, m;
    cin >> n >> m;

    vector<vector<int>> queries;
    for (int i = 0; i < n; i++) {
        vector<int> query;
        for (int j = 0; j < m; j++) {
            int input;
            cin >> input;

            query.push_back(input);
        }
        queries.push_back(query);
    }

    vector<int> answer = solution(rows, columns, queries);

    for (auto i: answer) {
        cout << i << ' ';
    }
}