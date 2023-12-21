#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string s;
    cin >> s;

    sort(s.begin(), s.end());

    int answer = 0;
    do {
        bool chk = true;
        for (int i = 0; i < s.length() - 1; i++) {
            if (s[i] == s[i + 1]) {
                chk = false;
            }
        }

        answer += chk;
    } while (next_permutation(s.begin(), s.end()));

    cout << answer;
}