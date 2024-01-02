#include <iostream>
#include <cmath>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<double, double> pdd;

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

    bool operator <(node& nd) {
        return this->cost < nd.cost;
    }
};

int cache[101];

double getDistance(const pdd& a, const pdd& b) {
    double c = a.first - b.first;
    double d = a.second - b.second;

    return sqrt(c * c + d * d);
}

int find(int n) {
    if (cache[n] == n)  {
        return n;
    }
    else {
        return cache[n] = find(cache[n]);
    }
}

void unionize(int a, int b) {
    a = find(a);
    b = find(b);
    cache[b] = a;
}

bool check(int a, int b) {
    a = find(a);
    b = find(b);

    return (a == b);
}

int main() {
    int n;
    cin >> n;

    vector<pdd> v;
    for (int i = 0; i < n; i++) {
        double a, b;
        cin >> a >> b;
        v.push_back({ a,b });
    }

    vector<node> v2;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            v2.push_back(node(i, j, getDistance(v[i], v[j])));
        }

        cache[i] = i;
    }

    sort(v2.begin(), v2.end());

    double answer = 0;
    for (int i = 0; i < v2.size(); i++) {
        if (check(v2[i].from, v2[i].to) == false) {
            unionize(v2[i].from, v2[i].to);
            answer += v2[i].cost;
        }
    }

    cout << fixed;
    cout.precision(2);
    cout << answer;
}