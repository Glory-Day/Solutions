#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;

    int cnt = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'P') {
            cnt++;
            continue;
        }

        if (cnt >= 2 && s[i + 1] == 'P') {
            cnt--;
            i++;
        }
        else {
            cout << "NP\n";
            return 0;
        }
    }

    if (cnt == 1) {
        cout << "PPAP\n";
    }  
    else {
        cout << "NP\n";
    }
}