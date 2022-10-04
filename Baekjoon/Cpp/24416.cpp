#include <iostream>

using namespace std;

int fib(int n) {
    if (n == 1 || n == 2) return 1;
    else return (fib(n - 1) + fib(n - 2));
}

int fibonacci(int n) {
    int answer = 0;
    for (int i = 3; i <= n; i++, answer++);
    return answer;
}

int main() {
    int n;
    cin >> n;

    cout << fib(n) << ' ' << fibonacci(n);
}