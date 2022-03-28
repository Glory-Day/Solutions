#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int m;
vector<pii> p1, p2;
int cache[1001][1001];

int getDistance(pii a, pii b) {
    return abs(b.first - a.first) + abs(b.second - a.second);
}

int dfs(int a, int b) {
    if (a == m || b == m) return cache[a][b] = 0;
    if (cache[a][b] != -1) return cache[a][b];

    int mx = max(a, b) + 1;
    int d1 = getDistance(p1[mx], p1[a]);
    int d2 = getDistance(p2[mx], p2[b]);

    d1 += dfs(mx, b);
    d2 += dfs(a, mx);

    return cache[a][b] = min(d1, d2);
}

string f(int a, int b) {
    string s = "";

    if (a == m || b == m) return s;

    int mx = max(a, b) + 1;
    int d1 = getDistance(p1[mx], p1[a]);
    int d2 = getDistance(p2[mx], p2[b]);

    if (cache[mx][b] + d1 > cache[a][mx] + d2) {
        s += "2";
        s += f(a, mx);
    }
    else {
        s += "1";
        s += f(mx, b);
    }

    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n >> m;

    p1.push_back({ 1,1 });
    p2.push_back({ n,n });
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        p1.push_back({ a,b });
        p2.push_back({ a,b });
    }

    fill(cache[0], cache[1000], -1);

    cout << dfs(0, 0) << '\n';

    string answer = f(0, 0);
    for (char& i: answer) {
        cout << i << '\n';
    }
}