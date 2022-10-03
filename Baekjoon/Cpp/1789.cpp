#include <iostream>

using namespace std;

typedef long long ll;

int main() {
    ll n;
    cin >> n;

    ll i;
    n *= 2;
    for (i = 1ll; i * (i + 1ll) <= n; i++);

    cout << i - 1ll;
}