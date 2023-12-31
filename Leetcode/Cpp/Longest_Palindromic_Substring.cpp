#include <iostream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

class Solution {
public:
    int check(string& s, int b, int e) {
        while (b >= 0 && e < s.length() && s[b] == s[e]) {
            b--;
            e++;
        }

        return e - b - 1;
    }

    string longestPalindrome(string s) {
        string answer = "";

        int l = 0, r = 0;
        for (int i = 0; i < s.size(); i++) {
            int a = check(s, i, i);
            int b = check(s, i, i + 1);

            int mx = max(a, b);
            if (mx > r) {
                l = i - (mx - 1) / 2;
                r = mx;
            }
        }

        answer = s.substr(l, r);

        return answer;
    }
};

int main() {
    string s;
    cin >> s;

    string answer = Solution().longestPalindrome(s);

    cout << answer;
}