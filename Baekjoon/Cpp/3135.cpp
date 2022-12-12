#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    int n;
    cin >> n;

    vector<int> arr = { abs(a - b) };
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        arr.push_back(abs(input - b) + 1);
    }

    sort(arr.begin(), arr.end());

    cout << arr[0];
}