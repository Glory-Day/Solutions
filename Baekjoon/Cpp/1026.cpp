#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a, b;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        a.push_back(input);
    }

    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        b.push_back(input);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), greater<int>());

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += (a[i] * b[i]);
    }

    cout << sum;
}