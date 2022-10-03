#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int answer = 0;
        string s;
        cin >> s;

        int j = 1;
        for (auto k: s) {
            (k == 'O') ? answer += j++ : j = 1;
        }

        cout << answer << '\n';
    }
}