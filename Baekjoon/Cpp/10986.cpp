#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    int mod = 0;
    ll answer = 0;
    vector<ll> cache(m, 0);
    for (int i = 1; i <= n; i++) {
        int input;
        cin >> input;
        
        mod = (mod + input) % m;

        cache[mod]++;
        if (mod == 0) answer++;
    }

    for (int i = 0; i < m; i++) {
        answer += cache[i] * (cache[i] - 1) / 2;
    }

    cout << answer;
}