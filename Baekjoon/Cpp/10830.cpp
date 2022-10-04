#include <iostream>
#include <vector>

#define MOD 1000

using namespace std;

typedef vector<vector<int>> vv;
typedef long long ll;

int n;
vv map;

vv f1(vv a, vv b) {
    vv c = vv(5, vector<int>(5, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int sum = 0;
            for (int l = 0; l < n; l++) {
                sum += (a[j][l] * b[l][i]) % MOD;
            }
            c[j][i] = sum % MOD;
        }
    }

    return c;
}

vv f2(ll b) {
    if (b <= 1) return map;

    vv c = f2(b / 2);

    if (b % 2) {
        c = f1(c, c);
        c = f1(c, map);

        return c;
    }
    else {
        return f1(c, c);
    }
}

int main() {
    ll b;
    cin >> n >> b;

    map = vv(5, vector<int>(5, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }

    vv answer = f2(b);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << answer[i][j] % MOD << ' ';
        }
        cout << '\n';
    }
}