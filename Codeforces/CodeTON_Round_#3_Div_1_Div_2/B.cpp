#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pllll;


int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        pllll cnt = { 0,0 };
        for (int i = 0; i < n; i++) {
            cnt.first += s[i] == '0';
            cnt.second += s[i] == '1';
        }

        ll tmp = 1;
        ll answer = cnt.first * cnt.second;
        for (int i = 1; i < n; i++) {
            if (s[i] == s[i - 1]) {
                tmp++;
            }
            else {
                answer = max(answer, tmp * tmp);
                tmp = 1;
            }
        }

        answer = max(answer, tmp * tmp);

        cout << answer << '\n';
    }
}