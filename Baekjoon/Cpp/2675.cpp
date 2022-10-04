#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int m;
        string s;
        cin >> m >> s;

        string answer = "";
        for (auto j: s) {
            for (int k = 0; k < m; k++) {
                answer += j;
            }
        }

        cout << answer << '\n';
    }
}