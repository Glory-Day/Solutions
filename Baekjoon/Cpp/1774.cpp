#include <iostream>
#include <cmath>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

class node {
public:
    int from;
    int to;
    double cost;

    node(int from, int to, double cost) {
        this->from = from;
        this->to = to;
        this->cost = cost;
    }

    bool operator <(const node& nd) {
        return this->cost < nd.cost;
    }
};

int cache[1001];

double getDistance(const pii& a, const pii& b) {
    ll c = a.first - b.first;
    ll d = a.second - b.second;

    return sqrt(c * c + d * d);
}

int find(int n) {
    if (cache[n] == n) {
        return n;
    }
    else {
        return cache[n] = find(cache[n]);
    }
}

bool unionize(int a, int b) {
    a = find(a);
    b = find(b);
    
    if (a == b) {
        return true;
    }
    else {
        cache[a] = b;
        return false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cache[i] = i;
    }

    vector<pii> v;
    v.push_back({ 0,0 });
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({ a,b });
    }

    vector<pii> v2;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        unionize(a, b);
    }

    vector<node> g;
    for (int i = 1; i <= n - 1; i++) {
        for (int j = i + 1; j <= n; j++) {
            g.push_back(node(i, j, getDistance(v[i], v[j])));
        }
    }

    sort(g.begin(), g.end());

    double answer = 0;
    for (int i = 0; i < (int)g.size(); i++) {
        if (unionize(g[i].from, g[i].to) == false) {
            answer += g[i].cost;
        }
    }

    cout << fixed;
    cout.precision(2);
    cout << answer;
}