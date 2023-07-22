#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>
#include <functional>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        string s[8];
        for (int i = 0; i < 8; i++) {
            cin >> s[i];
        }

        bool chk = false;
        int a, b;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (s[i][j] != '.') {
                    a = i, b = j;
                    chk = true;
                    break;
                }
            }

            if (chk) {
                break;
            }
        }

        string answer = "";
        for (int i = a; i < 8; i++) {
            char tmp = s[i][b];
            if (tmp != '.') {
                answer.push_back(tmp);
            }
        }

        cout << answer << '\n';
    }

    return 0;
}