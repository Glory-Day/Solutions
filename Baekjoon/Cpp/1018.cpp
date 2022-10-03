#include <iostream>
#include <string>

using namespace std;

char map[50][50];

string w[8] = { "WBWBWBWB","BWBWBWBW","WBWBWBWB","BWBWBWBW","WBWBWBWB","BWBWBWBW","WBWBWBWB","BWBWBWBW" };
string b[8] = { "BWBWBWBW","WBWBWBWB","BWBWBWBW","WBWBWBWB","BWBWBWBW","WBWBWBWB","BWBWBWBW","WBWBWBWB" };

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            map[i][j] = s[j];
        }
    }

    int answer = 251;
    for (int i = 0; i <= n - 8; i++) {
        for (int j = 0; j <= m - 8; j++) {
            int d1 = 0, d2 = 0;
            for (int k = 0; k < 8; k++) {
                for (int l = 0; l < 8; l++) {
                    if (map[i + k][j + l] != w[k][l]) {
                        d1++;
                    }
                    if (map[i + k][j + l] != b[k][l]) {
                        d2++;
                    }
                }
            }
            answer = min(answer, min(d1, d2));
        }
    }

    cout << answer;
}