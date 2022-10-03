#include <iostream>
#include <vector>

#define MOD 1000000007

using namespace std;

typedef long long ll;
typedef vector<vector<ll>> vv;

vv map;

vv f1(vv a, vv b) {
    vv c = vv(2, vector<ll>(2, 0));

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            int sum = 0;
            for (int l = 0; l < 2; l++) {
                sum += (a[j][l] * b[l][i]) % MOD;
            }
            c[j][i] = sum % MOD;
        }
    }

    return c;
}

vv f2(ll n) {
    if (n <= 1) return map;

    vv c = f2(n / 2);

    if (n % 2) {
        c = f1(c, c);
        c = f1(c, map);

        return c;
    }
    else {
        return f1(c, c);
    }
}

int main() {
    ll n;
    cin >> n;

    map = vv(2, vector<ll>(2, 0));

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (i == 1 && j == 1) map[i][j] = 0;
            else map[i][j] = 1;
            
        }
    }

    vv answer = f2(n);

    cout << answer[0][1];
}