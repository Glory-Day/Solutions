#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int h, w, m;
        cin >> h >> w >> m;

        string a = to_string((m % h == 0) ? h : m % h);
        string b = to_string((m <= h) ? 1 : (m % h == 0) ? m / h : m / h + 1);
        b = (b.size() == 1) ? "0" + b : b;

        cout << a + b << '\n';
    }
}