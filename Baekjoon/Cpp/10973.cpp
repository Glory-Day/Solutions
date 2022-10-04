#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        arr.push_back(input);
    }

    if (!prev_permutation(arr.begin(), arr.end())) cout << -1;
    else for (auto& i: arr) cout << i << ' ';
}