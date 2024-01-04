#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

class node {
public:
    int from;
    int to;
    int cost;

    node(int from, int to, int cost) {
        this->from = from;
        this->to = to;
        this->cost = cost;
    }

    bool operator <(const node& nd) {
        return this->cost < nd.cost;
    }
};

int cache[200001];

int find(int n) {
    if (cache[n] == n) {
        return n;
    }
    
    return cache[n] = find(cache[n]);
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
    vector<int> answer;
    while (true) {
        int n, m;
        cin >> m >> n;

        if (n == 0 && m == 0) {
            break;
        }

        for (int i = 0; i < m; i++) {
            cache[i] = i;
        }

        vector<node> g;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            g.push_back(node(a, b, c));

            sum += c;
        }

        sort(g.begin(), g.end());

        for (int i = 0; i < (int)g.size(); i++) {
            if (unionize(g[i].from, g[i].to) == false) {
                sum -= g[i].cost;
            }
        }

        answer.push_back(sum);
    }

    for (int& i: answer) {
        cout << i << '\n';
    }
}