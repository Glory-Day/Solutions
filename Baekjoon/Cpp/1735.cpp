#include <iostream>

using namespace std;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int na = a * d + c * b;
    int nb = b * d;

    int tmp = gcd(na, nb);

    cout << na / tmp << ' ' << nb / tmp;
}