#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    int mx = 0;
    int sum = 0;
    vector<int> arr;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        arr.push_back(input);
        mx = max(mx, input);
        sum += input;
    }

    cout << sum - mx;
}