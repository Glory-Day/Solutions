#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int answer = 0;
        
        int n;
        cin >> n;

        string s;
        cin >> s;

        for (int i = 0; i < n; i++) {
            answer = max(answer, s[i] - 'a' + 1);
        }

        cout << answer << '\n';
    }
}