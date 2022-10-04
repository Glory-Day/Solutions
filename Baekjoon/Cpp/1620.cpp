#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    unordered_map<string, int> mp;
    vector<string> arr;
    for (int i = 1; i <= n; i++) {
        string input;
        cin >> input;
        mp[input] = i;
        arr.push_back(input);
    }

    for (int i = 0; i < m; i++) {
        string input;
        cin >> input;

        if (all_of(input.begin(), input.end(), ::isdigit)) {
            cout << arr[stoi(input) - 1];
        }
        else {
            cout << mp[input];
        }

        cout << '\n';
    }
}