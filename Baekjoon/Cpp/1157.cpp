#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    int counts[26] = { 0, };

    string s;
    cin >> s;

    for (auto i: s) {
        counts[tolower(i) - 'a']++;
    }

    int m = -1;
    for (int& i: counts) {
        m = max(m, i);
    }

    int count = 0;
    for (int& i: counts) {
        count += (i == m) ? 1 : 0;
    }

    if (count > 1) {
        cout << '?';
    }
    else {
        for (char i = 'a'; i <= 'z'; i++) {
            if (m == counts[i - 'a']) {
                cout << (char)toupper(i);
            }
        }
    }
}