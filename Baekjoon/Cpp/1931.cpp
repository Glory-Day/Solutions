#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

typedef pair<int, int> pii;

bool compare(pii& a, pii& b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }

    return a.second < b.second;
}

int main() {
    int n;
    cin >> n;

    vector<pii> v;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({ a,b });
    }

    sort(v.begin(), v.end(), compare);

    int begin = 0, answer = 0;
    for (int i = 0; i < n; i++) {
        if (begin <= v[i].first) {
            begin = v[i].second;
            answer++;
        }
    }

    cout << answer;
}