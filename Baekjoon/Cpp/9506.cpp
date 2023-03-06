#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> f(int n) {
    vector<int> arr = { 1 };
    for (int i = 2; i * i <= n; i++) {
        if (i * i == n) {
            arr.push_back(n);
        }
        else if (n % i == 0) {
            arr.push_back(n / i);
            arr.push_back(i);
        }
    }

    return arr;
}

int main() {
    while (true) {
        int n;
        cin >> n;

        if (n == -1) {
            break;
        }

        int sum = 0;
        vector<int> arr = f(n);
        for (auto& i: arr) {
            sum += i;
        }

        sort(arr.begin(), arr.end());

        if (n == sum) {
            cout << n << " = ";
            for (int i = 0; i < arr.size() - 1; i++) {
                cout << arr[i] << " + ";
            }
            cout << arr[arr.size() - 1] << '\n';
        }
        else {
            cout << n << " is NOT perfect.\n";
        }
    }
}