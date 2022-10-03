#include <iostream>

using namespace std;

int a[100][100], b[100][100], answer[100][100];

int main() {
    int n, m, k;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    cin >> m >> k;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < k; j++) {
            cin >> b[i][j];
        }
    }

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            int sum = 0;
            for (int l = 0; l < m; l++) {
                sum += (a[j][l] * b[l][i]);
            }
            answer[i][j] = sum;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            cout << answer[j][i] << ' ';
        }
        cout << '\n';
    }
}