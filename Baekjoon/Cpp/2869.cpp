#include <iostream>

using namespace std;

int main() {
    int a, b, v;
    cin >> a >> b >> v;

    int answer = 1;
    int d = a - b;
    v -= a;

    if (v <= d) {
        answer += 1;
    }
    else if (v % d != 0) {
        answer += (v / d) + 1;
    }
    else {
        answer += (v / d);
    }

    if (v > 0) {
        cout << answer;
    }
    else {
        cout << 1;
    }
}