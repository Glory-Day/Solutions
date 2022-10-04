#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n;
    m = n;

    int i = 0;
    do {
        int a = m / 10;
        int b = m % 10;

        m = b * 10 + (a + b) % 10;
        i++;
    } while (m != n);

    cout << i;
}