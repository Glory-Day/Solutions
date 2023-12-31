#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int map[51][51];

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string input;
        cin >> input;
        for (int j = 0; j < m; j++) {
            map[i][j] = input[j] - '0';            
        }
    }

    int answer = 0;
    int len = min(n, m);
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < n - i; j++) {
            for (int k = 0; k < m - i; k++) {
                if (map[j][k] == map[j][k + i] &&
                    map[j][k] == map[j + i][k] &&
                    map[j][k] == map[j + i][k + i]) {
                    answer = max(answer, (i + 1) * (i + 1));
                }
            }
        }
    }

    cout << answer;
}