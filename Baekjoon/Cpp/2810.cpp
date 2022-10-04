#include <iostream>

using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    double answer = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'S') answer++;
        else answer += 0.5;
    }

    if (s.find('L') != string::npos) cout << answer + 1;
    else cout << answer;
}