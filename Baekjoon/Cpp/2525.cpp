#include <iostream>
#include <utility>

using namespace std;

typedef pair<int, int> pii;

int main() {
    pii s;
    cin >> s.first >> s.second;

    int m;
    cin >> m;

    s.first += m / 60;
    s.second += m % 60;

    if (s.second >= 60) {
        s.first++;
        s.second -= 60;
    }

    if (s.first >= 24) {
        s.first -= 24;
    }

    cout << s.first << ' ' << s.second;
}