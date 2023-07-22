#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>
#include <functional>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        vector<int> v(3);
        cin >> v[0] >> v[1] >> v[2];

        sort(v.begin(), v.end());

        if (v[1] + v[2] < 10) {
            cout << "NO\n";
        }
        else {
            cout << "YES\n";
        }
    }

    return 0;
}