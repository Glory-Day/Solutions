#include <iostream>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}

int main() {
    int a, b;
    cin >> a >> b;

    cout << lcm(a, b);
}