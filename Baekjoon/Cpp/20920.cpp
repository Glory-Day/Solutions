#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<string, int> psi;

bool compare(const psi& a, const psi& b) {
    if (a.second == b.second) {
        if (a.first.length() == b.first.length()) {
            return a < b;
        }

        return a.first.length() > b.first.length();
    }

    return a.second > b.second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    map<string, int> mp;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        if (s.length() < m) {
            continue;
        }

        if (mp.find(s) == mp.end()) {
            mp[s] = 1;
        }
        else {
            mp[s]++;
        }
    }

    vector<psi> v;
    for (auto it = mp.begin(); it != mp.end(); it++) {
        v.push_back(*it);
    }

    sort(v.begin(), v.end(), compare);

    for (auto& i: v) {
        cout << i.first << '\n';
    }
}