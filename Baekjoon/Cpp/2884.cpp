#include <iostream>

using namespace std;

int main() {
    int h, m;
    cin >> h >> m;

    m += h * 60 - 45;

    if (m < 0) {
        m += 24 * 60;
    }

    h = m / 60;
    m %= 60;

    cout << h << ' ' << m;
}