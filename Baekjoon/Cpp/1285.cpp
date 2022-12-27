#include <iostream>
#include <climits>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    string map[20];
    for (int i = 0; i < n; i++) {
        cin >> map[i];
    }

    int answer = INT_MAX;
    for (int i = 0; i < (1 << n); i++) {
        int mn = 0;
        for (int j = 0; j < n; j++) {
            int cnt = 0;
            for (int k = 0; k < n; k++) {
                bool chk = map[j][k] == 'H';
                if ((i & (1 << k)) != 0) {
                    chk = !chk;
                }

                if (chk) {
                    cnt++;
                }
            }

            mn += min(cnt, n - cnt);
        }

        answer = min(answer, mn);
    }

    cout << answer;
}