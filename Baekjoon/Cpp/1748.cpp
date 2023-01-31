#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int a = 1, b = 1;
    while (a * 10 <= n) {
        a *= 10;
        b++;
    }

    long long answer = 0;
    while (a != 0) {
        answer += (n - a + 1) * b;
        n = a - 1;
        a /= 10;
        b--;
    }

    cout << answer;
}