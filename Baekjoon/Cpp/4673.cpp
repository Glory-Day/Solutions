#include <iostream>
#include <string>

using namespace std;

bool visited[10001];

int d(int n) {
    string s = to_string(n);

    for (auto i: s) {
        n += (i - '0');
    }

    return n;
}

void check(int n) {
    if (n > 10000) return;

    int num = d(n);
    visited[num] = true;

    check(num);
}

int main() {
    for (int i = 1; i <= 10000; i++) {
        if (!visited[i]) {
            check(i);
        }
    }

    for (int i = 1; i <= 10000; i++) {
        if (!visited[i]) {
            cout << i << '\n';
        }
    }
}