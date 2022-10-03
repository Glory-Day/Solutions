#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<ll> v;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        v.push_back(input);
    }

    sort(v.begin(), v.end());

    ll g = 0;
    ll d = v[1] - v[0];
    for (int i = 1; i < n - 1; i++) {
        d = gcd(d, v[i + 1] - v[i]);
    }

    g = d;

    vector<ll> answer;
    for (ll i = 2; i * i <= g; i++) {
        if (g % i == 0) {
            answer.push_back(i);
            answer.push_back(g / i);
        }
    }

    answer.push_back(g);

    sort(answer.begin(), answer.end());
    answer.erase(unique(answer.begin(), answer.end()), answer.end());

    for (ll& i: answer) {
        cout << i << ' ';
    }
}