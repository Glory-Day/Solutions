#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int map[21][21];
bool visited[21];
int len, answer = 10000001;

void f(int nt, int lv) {
    if (lv == len / 2) {
        int a = 0, b = 0;
        for (int i = 1; i <= len; i++) {
            for (int j = i + 1; j <= len; j++) {
                if (visited[i] && visited[j]) {
                    a += map[i][j] + map[j][i];
                }
                else if (!visited[i] && !visited[j]) {
                    b += map[i][j] + map[j][i];
                }
            }
        }
        answer = min(answer, abs(a - b));
        return;
    }

    for (int i = 1; i <= len; i++) {
        if (!visited[i] && i > nt) {
            visited[i] = true;
            f(i, lv + 1);
            visited[i] = false;
        }
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> map[i][j];
        }
    }

    len = n;

    f(0, 0);

    cout << answer;
}