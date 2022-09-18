#include <iostream>
#include <string>

using namespace std;

int answer;

bool recursion(string& s, int l, int r) {
    answer++;
    if (l >= r) {
        return 1;
    }
    else if (s[l] != s[r]) {
        return 0;
    }
    else {
        return recursion(s, l + 1, r - 1);
    }
}

bool isPalindrome(string& s) {
    return recursion(s, 0, s.length() - 1);
} 

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        answer = 0;
        string input;
        cin >> input;
        cout << isPalindrome(input) << ' ' << answer << '\n';
    }
}