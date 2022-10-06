#include <iostream>
#include <climits>
#include <string>
#include <algorithm>

using namespace std;

void change(string& a, int idx) {
    for (int i = idx - 1; i <= idx + 1; i++) {
        if (i < 0 || i >= a.size()) {
            continue;
        }

        a[i] = (a[i] == '1') ? '0' : '1';
    }
}

int check(string a, string b, int n, bool chk) {
    int cnt = 0;

    if (chk) {
        change(a, 0);
        cnt++;
    }

    for (int i = 1; i < n; i++) {
        if (a[i - 1] != b[i - 1]) {
            change(a, i);
            cnt++;
        }
    }

    if (a != b) {
        cnt = INT_MAX;
    }

    return cnt;
}

int main() {
    int n;
    cin >> n;

    string a, b;
    cin >> a >> b;

    int answer = min(check(a, b, n ,false), check(a, b, n, true));
    if (answer == INT_MAX) {
        cout << -1;
    }
    else {
        cout << answer;
    }
}