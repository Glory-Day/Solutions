#include <iostream>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;

int main() {
    string s;
    cin >> s;

    sort(s.begin(), s.end(), greater<char>());

    int sum = 0;
    for (char& i: s) {
        sum += (i - '0');
    }

    if (sum % 3 != 0 || s.back() != '0') cout << -1;
    else cout << s;
}