#include <iostream>
#include <cctype>
#include <climits>
#include <cmath>
#include <string>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int answer = 0;

        int i = 0, sign = 1, n = 0;
        if (s.length() == 0) {
            return 0;
        }
        while (isspace(s[i])) {
            ++i;
        }
        sign = (s[i] == '-') ? -1 : 1;
        if (s[i] == '+' || s[i] == '-') {
            i++;
        }
        while (isdigit(s[i])) {
            if (n > INT_MAX / 10 || (n == INT_MAX / 10 && s[i] - '0' > 7)) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }
            n = n * 10 + (s[i++] - '0');
        }

        answer = sign * n;

        return answer;
    }
};

int main() {
    string s;
    getline(cin, s);

    int answer = Solution().myAtoi(s);

    cout << answer;
}