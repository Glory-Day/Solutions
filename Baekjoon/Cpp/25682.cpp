#include <iostream>
#include <climits>
#include <string>
#include <algorithm>
#include <memory.h>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    char map[2001][2001];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    int matrix[2001][2001];
    memset(matrix, 0, sizeof(matrix));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int tmp;
            if ((i + j) % 2 == 0) {
                tmp = map[i][j] != 'B';
            }
            else {
                tmp = map[i][j] == 'B';
            }

            matrix[i + 1][j + 1] = matrix[i][j + 1] + matrix[i + 1][j] - matrix[i][j] + tmp;
        }
    }

    int answer = INT_MAX;
    for (int i = 1; i <= n - k + 1; i++) {
        for (int j = 1; j <= m - k + 1; j++) {
            answer = min(answer, matrix[i + k - 1][j + k - 1] - matrix[i + k - 1][j - 1] - matrix[i - 1][j + k - 1] + matrix[i - 1][j - 1]);
        }
    }

    memset(matrix, 0, sizeof(matrix));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int tmp;
            if ((i + j) % 2 == 0) {
                tmp = map[i][j] != 'W';
            }
            else {
                tmp = map[i][j] == 'W';
            }

            matrix[i + 1][j + 1] = matrix[i][j + 1] + matrix[i + 1][j] - matrix[i][j] + tmp;
        }
    }

    for (int i = 1; i <= n - k + 1; i++) {
        for (int j = 1; j <= m - k + 1; j++) {
            answer = min(answer, matrix[i + k - 1][j + k - 1] - matrix[i + k - 1][j - 1] - matrix[i - 1][j + k - 1] + matrix[i - 1][j - 1]);
        }
    }

    cout << answer;
}