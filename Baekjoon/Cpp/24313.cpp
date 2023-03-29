#include <iostream>

using namespace std;

int main() {
    int a, b, c, n;
    cin >> a >> b >> c >> n;

    bool answer = (a * n + b <= c * n) && (c - a >= 0);
    cout << answer;
}