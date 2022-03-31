#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<int> v;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        v.push_back(input);
    }

    sort(v.begin(), v.end());

    cin >> n;

    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;

        int b = lower_bound(v.begin(), v.end(), input) - v.begin();
        int e = upper_bound(v.begin(), v.end(), input) - v.begin();
        
        cout << e - b << ' ';
    }
}