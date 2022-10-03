#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string s;
    cin >> s;

    int a = 0, b = 0;
    for (int i = 0; i < s.size() - 1; i++) {
        if (s[i] != s[i + 1]) {
            if (s[i] == '0') a++;
            else b++;
        }
    }

    if (s.back() == '0') a++;
    else b++;

    cout << min(a, b);
}