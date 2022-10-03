#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    int answer = 10000;
    for (int i = 1, j = 5; j <= n; i++, j += 5) {
        int m = n - j;
        int k = 0;
        if (m % 3 == 0) {
            k = m / 3;
            answer = min(answer, i + k);
        }
        else {
            continue;
        }
    }

    if (answer == 10000) {
        cout << ((n % 3 == 0) ? n / 3 : -1);
    }
    else {
        cout << answer;
    }
}