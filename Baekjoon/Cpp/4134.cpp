#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

bool isPrime(ll n) {
    if (n == 0 || n == 1) {
        return false;
    }

    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        ll input;
        cin >> input;

        ll answer;
        while (true) {
            if (isPrime(input)) {
                answer = input;
                break;
            }
            else {
                input++;
            }
        }

        cout << answer << '\n';
    }
}