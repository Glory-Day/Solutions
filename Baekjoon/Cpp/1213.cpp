#include <iostream>
#include <string>

using namespace std;

int cnts[26];

int main() {
    string s;
    cin >> s;

    for (int i = 0; i < s.size(); i++) {
        cnts[s[i] - 'A']++;
    }

    int odd = 0;
    for (int i = 0; i < 26; i++) {
        if (cnts[i] % 2 != 0) odd++;
    }

    if (odd > 1) {
        cout << "I\'m Sorry Hansoo";
    }
    else {
        for(int i = 0; i < 26; i++) {
            for(int j = 0; j < cnts[i] / 2; j++) {
                cout << (char)('A' + i);
            }
        }

        for(int i = 0; i < 26; i++) {
            if(cnts[i]%2) {
                cout << (char)('A' + i);
            }
        }

        for(int i = 25; i >= 0; i--) {
            for(int j = 0; j < cnts[i]/2; j++) {
                cout << (char)('A' + i);
            }
        }
    }
}