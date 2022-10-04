#include <iostream>
#include <string>

using namespace std;

bool cache[1001];

void check(int n) {
    string s = to_string(n);
    int a = (s[0] - '0') - (s[1] - '0');
    int b = (s[1] - '0') - (s[2] - '0');

    if (a != b) {
        cache[n] = true;
    }
}

int main() {
    int n;
    cin >> n;

    for (int i = 100; i <= n; i++) {
        check(i);
    }

    int answer = 0;
    for (int i = 1; i <= n; i++) {
        answer += (!cache[i]) ? 1 : 0;
    }

    cout << answer;
}