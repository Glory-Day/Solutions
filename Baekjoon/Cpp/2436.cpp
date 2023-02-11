#include <iostream>
#include <utility>

using namespace std;

typedef pair<long long, long long> pllll;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }

    return gcd(b, a % b);
}

int main() {
    int a, b;
    cin >> a >> b;

    b = b / a;

    int c = 0;
    for (int i = 1; i * i <= b; i++) {
        if (b % i == 0 && gcd(i, b / i) == 1) {
            c = i;
        }
    }

    pllll answer = { a * c,a * (b / c)};

    cout << answer.first << ' ' << answer.second;
}