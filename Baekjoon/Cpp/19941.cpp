#include <iostream>
#include <string>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    int answer = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] != 'P') {
            continue;
        }

        for (int j = i - k; j <= i + k; j++) {
            if (0 <= j && j < n && s[j] == 'H') {
                answer++, s[j] = 'X';
                break;
            }
        }
    }

    cout << answer;   
}