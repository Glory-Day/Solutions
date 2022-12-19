#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

typedef long long ll;

int main() {
    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        int answer = (s[0] - '0') + (s[2] - '0');

        cout << answer << '\n';
    }
}