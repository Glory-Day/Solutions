#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

bool compare(pair<pair<int, int>, int>& a, pair<pair<int, int>, int>& b) {
    if (a.first.first == b.first.first) {
        return a.first.second < b.first.second;
    }

    return a.first.first > b.first.first;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m, h;
        cin >> n >> m >> h;

        vector<pair<pair<int, int>, int>> answer;
        
        vector<int> v(m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> v[j];
            }

            sort(v.begin(), v.end());

            pair<int, int> p = { 0,0 };
            int nh = h;
            int prev = 0;
            for (int j = 0; j < m; j++) {                
                nh -= v[j];

                if (nh < 0) {
                    break;
                }

                p.first++;
                prev += v[j];
                p.second += prev;
            }

            answer.push_back({p, i});
        }

        sort(answer.begin(), answer.end(), compare);

        for (int i = 0; i < n; i++) {
            if (answer[i].second == 0) {
                cout << i + 1 << '\n';
            }
        }
    }
}