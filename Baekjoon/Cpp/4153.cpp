#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    while (true) {
        int a[3];
        cin >> a[0] >> a[1] >> a[2];

        sort(a, a + 3);

        if (a[0] == 0 && a[1] == 0 && a[2] == 0) {
            break;
        }
        else if (a[2] * a[2] == a[0] * a[0] + a[1] * a[1]) {
            cout << "right\n";
        }
        else {
            cout << "wrong\n";
        }
    }
}