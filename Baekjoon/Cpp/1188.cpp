#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }

    return gcd(b, a % b);
}

int main() {
    int n, m;
    cin >> n >> m;

    int answer = m - gcd(n, m);

    cout << answer;
}