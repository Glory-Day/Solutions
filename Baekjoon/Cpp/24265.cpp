#include <iostream>

using namespace std;

typedef long long ll;

int main() {
    ll n;
    cin >> n;

    ll answer = (n * n - n) / 2;
    cout << answer << '\n' << 2;
}