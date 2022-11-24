#include <iostream>
#include <climits>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int answer = 0;

        string s = "";
        if (x < 0) {
            s = to_string(abs(x));
            s.push_back('-');
            std::reverse(s.begin(), s.end());
        }
        else {
            s = to_string(x);
            std::reverse(s.begin(), s.end());
        }

        if (INT32_MIN <= stoll(s) && stoll(s) <= INT32_MAX) {
            answer = stoll(s);
        }

        return answer;
    }
};

int main() {
    int x;
    cin >> x;

    int answer = Solution().reverse(x);

    cout << answer;
}