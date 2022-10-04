#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

typedef pair<int, pair<int, string>> pipis;

bool compare(pipis& a, pipis& b) {
    if (a.first == b.first) {
        return a.second.first < b.second.first;
    }
    return a.first < b.first;
}

int main() {
    int n;
    cin >> n;

    vector<pipis> v;
    for (int i = 0; i < n; i++) {
        int input;
        string s;
        cin >> input >> s;
        v.push_back({ input,{ i,s } });
    }

    sort(v.begin(), v.end(), compare);

    for (auto i: v) {
        cout << i.first << ' ' << i.second.second << '\n';
    }
}