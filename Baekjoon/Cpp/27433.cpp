#include <iostream>

using namespace std;

long long f(int n) {
    return (n <= 1) ? 1 : f(n - 1) * n;
}

int main() {
    int n;
    cin >> n;
    cout << f(n);
}