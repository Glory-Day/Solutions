#include <iostream>

using namespace std;

typedef long long ll;

int main() {
    ll a, b, c;
    cin >> a >> b >> c;

    if (b >= c) {
        cout << -1;
    }
    else {
        cout << a / (c - b) + 1;
    }
}