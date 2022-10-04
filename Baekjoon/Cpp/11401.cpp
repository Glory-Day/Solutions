#include <iostream>

#define MOD 1000000007

using namespace std;

typedef long long ll;

ll num;

ll factorial(ll n) {
   ll num = 1;

   while (n > 1) {
       num = (num * n--) % MOD;
   }

   return num;
}

int f(ll a, int b) {
    if (b <= 1) return a % MOD;

    num = f(a, b / 2);

    if (b % 2) {
        return ((num * num) % MOD * a) % MOD;
    }
    else {
        return (num * num) % MOD;
    }
}

int main() {
    int n, k;
    cin >> n >> k;

    ll a = factorial(n);
    ll b = factorial(k) * factorial(n - k) % MOD;

    cout << (a * f(b, MOD - 2)) % MOD;
}