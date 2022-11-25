#include <iostream>
#include <climits>
#include <string>
#include <vector>
#include <utility>

using namespace std;

typedef pair<int, int> pii;

int map[1001][1001];

int main() {
    int n, m;
    cin >> n >> m;

    string answer = "";
    if (n % 2 == 1) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m - 1; j++) {
                if (i % 2 == 0) {
                    answer += 'R';
                }
                else {
                    answer += 'L';
                }
            }

            if (i != n - 1) {
                answer += 'D';
            }
        }
    }
    else if (n % 2 == 0 && m % 2 == 1) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n - 1; j++) {
                if (i % 2 == 0) {
                    answer += 'D';
                }
                else {
                    answer += 'U';
                }
            }

            if (i != m - 1) {
                answer += 'R';
            }
        }
    }
    else if (n % 2 == 0 && m % 2 == 0) {
        pii p;
        int mn = INT32_MAX;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> map[i][j];
                if ((i + j) % 2 == 1 && mn > map[i][j]) {
                    mn = map[i][j];
                    p = { i,j };
                }
            }
        }

        pii np = { ((p.first % 2 == 1) ? p.first - 1 : p.first),p.second };
        for (int i = 0; i < np.first; i++) {
            for (int j = 0; j < m - 1; j++) {
                if (i % 2 == 0) {
                    answer += 'R';
                }
                else {
                    answer += 'L';
                }
            }
            answer += 'D';
        }

        for (int i = 0; i < np.second; i++) {
            if (i % 2 == 0) {
                answer += "DR";
            }
            else {
                answer += "UR";
            }
        }

        for (int i = np.second; i < m - 1; i++) {
            if (i % 2 == 0) {
                answer += "RD";
            }
            else {
                answer += "RU";
            }
        }

        if (p.first % 2 == 0) {
            np.first = n - (p.first + 2);
        }
        else {
            np.first = n - (p.first + 1);
        }

        for (int i = 0; i < np.first; i++) {
            answer += 'D';
            for (int j = 0; j < m - 1; j++) {
                if (i % 2 == 0) {
                    answer += 'L';
                }
                else {
                    answer += 'R';
                }
            }
        }
    }

    cout << answer;
}