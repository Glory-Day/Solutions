#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> arr;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        arr.push_back(input);
    }

    int sum = 0;
    vector<int> prefix = { 0 };
    for (auto& i: arr) {
        sum += i;
        prefix.push_back(sum);
    }

    for (int i = 0; i < m; i++) {
        int b, e;
        cin >> b >> e;
        cout << prefix[e] - prefix[b - 1] << '\n';
    }
}