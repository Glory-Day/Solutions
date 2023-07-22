#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>
#include <functional>

using namespace std;

bool comp(vector<int>& a, vector<int>& b) {
    return a.size() > b.size();
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> v;
        for (int i = 0; i < n; i++) {
            int input;
            cin >> input;
            v.push_back(input);
        }

        sort(v.begin(), v.end());

        vector<int> stk;
        vector<vector<int>> vv;
        for (int i = 0; i < n; i++) {
            if (stk.empty() || (v[i] - stk.back()) <= k) {
                stk.push_back(v[i]);
            }
            else {
                vv.push_back(stk);
                stk.clear();
                stk.push_back(v[i]);
            }
        }
        vv.push_back(stk);

        int tmp = -1;
        for (auto& i: vv) {
            tmp = max(tmp, (int)i.size());
        }
        cout << n - tmp << '\n';
    }

    return 0;
}