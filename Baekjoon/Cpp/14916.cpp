#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int answer = 0;
    int mod = n % 2;
    if (mod && n >= 5) {
        answer++;
        n -= 5;
    }

    while (n >= 10) {
        n -= 10;
        answer += 2;
    }

    while (n >= 2) {
        n -= 2;
        answer++;
    }

    if (n) cout << -1;
    else cout << answer;
}