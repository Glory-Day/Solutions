#include <iostream>
#include <string>
#include <algorithm>
#include <utility>

using namespace std;

typedef pair<int, int> pii;

int map[2][51][51];

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            string input;
            cin >> input;
            for (int k = 0; k < m; k++) {
                map[i][j][k] = input[k] - '0';
            }
        }
    }

    if (n < 3 || m < 3) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (map[0][i][j] != map[1][i][j]) {
                    cout << -1;
                    return 0;
                }
            }
        }
    }

    
    int answer = 0;
    for (int i = 0; i < n - 2; i++) {
        for (int j = 0; j < m - 2; j++) {
            if (map[0][i][j] != map[1][i][j]) {
                for (int ni = i; ni <= i + 2; ni++) {
                    for (int nj = j; nj <= j + 2; nj++) {
                        map[0][ni][nj] = map[0][ni][nj] ^ 1;
                    }
                }
                answer++;
            }
            else {
                continue;
            }
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (map[0][i][j] != map[1][i][j]){
                cout << "-1";
                return 0;
            }
        }
    }

    cout << answer;
}