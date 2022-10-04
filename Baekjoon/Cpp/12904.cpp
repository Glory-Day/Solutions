#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string a, b;
    cin >> a >> b;

    int answer = 0;
    while (!b.empty()) {
        if (a.size() == b.size() && a == b) {
            answer = 1;
            break;
        }

        if (b.back() == 'A') {
            b.pop_back();
        }
        else {
            b.pop_back();
            reverse(b.begin(), b.end());
        }
    }

    cout << answer;
}