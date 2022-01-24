#include <iostream>

using namespace std;

typedef long long ll;

ll fibonacci(int n) {
    if (n <= 0) return 0;
    else if (n == 1 || n == 2) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;
    cin >> n;
    cout << fibonacci(n);
}