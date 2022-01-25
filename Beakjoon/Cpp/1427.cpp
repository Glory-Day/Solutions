#include <iostream>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;

int main() {
    string s;
    cin >> s;

    sort(s.begin(), s.end(), greater<char>());

    cout << s;
}