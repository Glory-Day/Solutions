#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int m;
    for (m = 1; m < n; n -= m, m++);

    int a, b;
    if (m % 2 == 0) {
        a = 1, b = m;
        a += n - 1;
        b -= n - 1;
    }
    else {
        a = m, b = 1;
        a -= n - 1;
        b += n - 1;
    }

    cout << a << '/' << b;
}