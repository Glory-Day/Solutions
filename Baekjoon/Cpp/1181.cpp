#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

typedef pair<int, string> pis;

int main() {
    int n;
    cin >> n;

    vector<pis> v;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        v.push_back({ s.size(),s });
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    for (auto i: v) {
        cout << i.second << '\n';
    }
}