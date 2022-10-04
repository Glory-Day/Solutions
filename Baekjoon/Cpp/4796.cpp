#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int i = 0;
    while (++i) {
        int l, p, v;
        cin >> l >> p >> v;

        if (l == 0 && p == 0 && v == 0) break;

        int answer = (v / p) * l;
        int mod = min(v % p, l);

        cout << "Case " << i << ": " << answer + mod << '\n';
    }
}