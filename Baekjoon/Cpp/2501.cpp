#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> f(int n) {
    vector<int> arr = { 1,n };
    for (int i = 2; i * i <= n; i++) {
        if (i * i == n) {
            arr.push_back(i);
        }
        else if (n % i == 0) {
            arr.push_back(i);
            arr.push_back(n / i);
        }
    }

    sort(arr.begin(), arr.end());

    return arr;
}

int main() {
    int n, k;
    cin >> n >> k;

    int answer = f(n)[k - 1];

    cout << answer;
}