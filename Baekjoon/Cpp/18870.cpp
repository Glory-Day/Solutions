#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

typedef pair<int, pair<int, int>> pipii;

bool compare1(pipii& a, pipii& b) {
    return a.second.first < b.second.first;
}

bool compare2(pipii& a, pipii& b) {
    return a.first < b.first;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<pipii> v;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        v.push_back({ i,{ input,0 } });
    }

    sort(v.begin(), v.end(), compare1);

    int c = 0;
    for (int i = 0; i < n - 1; i++) {
        v[i].second.second = c;
        if (v[i].second.first < v[i + 1].second.first) {
            c++;
        }
    }

    v[n - 1].second.second = c;

    sort(v.begin(), v.end(), compare2);

    for (auto i: v) {
        cout << i.second.second << ' ';
    }
}