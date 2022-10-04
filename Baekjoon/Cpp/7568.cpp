#include <iostream>
#include <vector>
#include <utility>

using namespace std;

typedef pair<int, int> pii;

int main() {
    int n;
    cin >> n;

    vector<pii> v;
    for (int i = 0; i < n; i++) {
        int w, h;
        cin >> w >> h;
        v.push_back({ w,h });
    }

    for (int i = 0; i < n; i++) {
        int r = 1;
        for (int j = 0; j < n; j++) {
            if (v[i].first < v[j].first && v[i].second < v[j].second) {
                r++;
            }
        }
        cout << r << ' ';
    }
}