#include <iostream>
#include <map>
#include <algorithm>
#include <utility>

using namespace std;

typedef long long ll;
typedef pair<int, ll> pill;

ll answer[300001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    map<int, ll> mp;
    map<int, ll>::iterator b, e;

    mp.insert(pill(0, -1));
    mp.insert(pill(300001, -1));

    ll cnt = 0;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;

        ll lv = 0;
        b = --mp.lower_bound(input);
        e = mp.upper_bound(input);
        lv = max((*b).second, (*e).second) + 1;

        mp.insert(pill(input, lv));
        cnt += lv;

        answer[i] = cnt;
    }

    for (int i = 0; i < n; i++) {
        cout << answer[i] << '\n';
    }
}