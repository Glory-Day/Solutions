#include <iostream>

using namespace std;

typedef long long ll;

int main() {
    ll n;
    cin >> n;

    ll answer = n * (n - 1) * (n - 2) / 6;
    cout << answer << '\n' << 3;    
}