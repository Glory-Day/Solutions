#include <iostream>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int sum = 0;
    for (int i = 1; i <= k; i++) {
        sum += i;
    }

    n -= sum;

    if (n < 0) {
        cout << -1;
    }
    else {
        if (n % k == 0) {
            cout << k - 1;
        }
        else {
            cout << k;
        }
    }
}