#include <iostream>

using namespace std;

typedef long long ll;

ll num;

int f(int a, int b, int c) {
    if (b <= 1) return a % c;

    num = f(a, b / 2, c);

    if (b % 2) {
        return ((num * num) % c * a) % c;
    }
    else {
        return (num * num) % c;
    }
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    int answer = f(a, b, c);

    cout << answer;
}