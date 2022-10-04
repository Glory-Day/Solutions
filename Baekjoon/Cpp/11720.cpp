#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    n = 0;
    for (auto i: s) {
        n += i - '0';
    }

    cout << n;
}