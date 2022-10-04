#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

ll cache[101];
string scache[101];

vector<int> init(string s) {
    int tmp = 0;
    vector<int> arr(s.size());
    for (int i = 1; i < s.size(); i++) {
        while (tmp > 0 && s[i] != s[tmp]) tmp = arr[tmp - 1];
        arr[i] = tmp = (s[i] == s[tmp]) ? tmp + 1 : 0;
    }

    return arr;
}

vector<int> kmp(string s, string p, int idx) {
    vector<int> answer;
    vector<int> arr = init(p);

    int i = 0, j = 0;
    while (i + j < s.size()) {
        if (j > idx) break;
        if (s[i + j] == p[i]) {
            if (i == p.size() - 1) answer.push_back(j);
            else { i++; continue; }
        }

        if (i > 0) j += (i - arr[i - 1]), i = arr[i - 1];
        else j++, i = 0;
    }

    return answer;
}

ll find(int n, string p) {
    if (p == "0") {
        if (n < 2) return (n == 0) ? 1 : 0;
        return cache[n - 2];
    }

    if (p == "1") {
        if (n < 2) return (n == 0) ? 0 : 1;
        return cache[n - 1];
    }

    int idx = 3;
    while (cache[idx - 3] <= p.size()) idx++;
    if (idx > n) idx = n;

    ll a = 0, b = 0, bit[2] = { 0,0 };
    vector<int> pt = kmp(scache[idx], p, (int)cache[idx - 1]);
    for (int& i: pt) {
        if (i < cache[idx - 2]) {
            if ((ll)(i + p.size() - 1) < cache[idx - 2]) b++;
            else bit[0]++;
        }
        else if (i < cache[idx - 1]) {
            if ((ll)(i + p.size() - 1) < cache[idx - 1]) a++;
            else bit[1]++;
        }
    }

    for (int i = 0; i <= n - idx + 1; i++) {
        ll tmp = b;
        b += (a + bit[i % 2]);
        a = tmp;
    }

    return b;
}

int main() {
    scache[0] = "0", scache[1] = "1";
    cache[0] = cache[1] = 1;

    for (int i = 1; i < 3 || scache[i - 3].size() < 100000; i++) {
        scache[i + 1] = scache[i] + scache[i - 1];
    }

    for (int i = 1; i < 100; i++) {
        cache[i + 1] = cache[i] + cache[i - 1];
    }

    int n;
    string p;
    for (int i = 1; cin >> n >> p; i++) {
        cout << "Case " << i << ": " << find(n, p) << '\n';
    }
}