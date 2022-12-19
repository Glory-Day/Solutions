#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

typedef long long ll;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int map[2][2];
        cin >> map[0][0] >> map[0][1];
        cin >> map[1][0] >> map[1][1];

        string answer = "NO";
        for (int i = 0; i < 4; i++) {
            if (map[0][0] < map[0][1] && map[1][0] < map[1][1] && map[0][0] < map[1][0] && map[0][1] < map[1][1]) {
                answer = "YES";
            }

            int temp[2][2];
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    temp[k][2-j-1] = map[j][k];
                }
            }

            copy(&temp[0][0], &temp[0][0] + 4, &map[0][0]);
        }

        cout << answer << '\n';
    }
}