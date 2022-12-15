#include <iostream>
#include <string>
#include <algorithm>
#include <utility>

using namespace std;

typedef pair<int, int> pii;

int main() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    bool chk = false;
    char b = s[0];
    pii tmp = { 0,0 };
    for (int i = 0; i < n; i++) {
        if (b != s[i]) {
            tmp.second++;
            chk = true;
        }
        else if (chk) {
            tmp.first++;
        }
    }

    int answer = min(tmp.first, tmp.second);

    chk = false;
    b = s[n - 1];
    tmp = { 0,0 };
    for (int i = n - 1; i >= 0; i--) {
        if (b != s[i]) {
            tmp.second++;
            chk = true;
        }
        else if (chk) {
            tmp.first++;
        }
    }

    answer = min(answer, min(tmp.first, tmp.second));

    cout << answer;
}