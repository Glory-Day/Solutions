#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int map[2001][101];

bool compare(pii& a, pii& b) {
    if (a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}

int getIndex(int b, int n) {
    int idx = n;
    vector<int> idxs;
    for (int i = 1; i <= n; i++) {
        if (map[b][i]) idxs.push_back(i);
    }

    if (idxs.empty()) return 1;
    else if (idxs.size() == 1) {
        if (idxs[0] - 1 < n - idxs[0]) return n;
        else return 1;
    }
    else {
        int mx = -1;

        if (idxs.back() != n) {
            if (mx <= n - idxs.back() - 1) {
                mx = n - idxs.back() - 1;
                idx = n;
            }
        }
        if (idxs.front() != 1) {
            if (mx <= idxs.front() - 2) {
                mx = idxs.front() - 2;
                idx = 1;
            }
        }

        for (int i = 0; i < idxs.size() - 1; i++) {
            int d = (idxs[i + 1] - idxs[i]) / 2 - 1;
            if (mx < d) {
                mx = d;
                idx = (idxs[i + 1] + idxs[i]) / 2;
            }
            else if (mx == d) {
                idx = min(idx, (idxs[i + 1] + idxs[i]) / 2);
            }
        }
    }

    return idx;
}

int getMinute(string s) {
    int h = (s[0] - '0') * 10 + (s[1] - '0');
    int m = (s[2] - '0') * 10 + (s[3] - '0');

    return h * 60 + m;
}

int main() {
    int n, t, p;
    cin >> n >> t >> p;

    vector<pii> v;
    for (int i = 0; i < t; i++) {
        string a, b;
        cin >> a >> b;
        v.push_back({ getMinute(a),getMinute(b) });
    }

    sort(v.begin(), v.end(), compare);

    for (int i = 0; i < t; i++) {
        int b = v[i].first, e = v[i].second;
        int idx = getIndex(b, n);
        for (int j = b; j < e; j++) {
            map[j][idx] = i + 1;
        }
    }

    int answer = 0;
    int b = getMinute("0900");
    int e = getMinute("2100");
    for (int i = b; i < e; i++) {
        if (!map[i][p]) answer++;
    }

    cout << answer;
}