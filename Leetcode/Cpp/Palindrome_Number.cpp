#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        string number = to_string(x);

        int b = 0, e = number.size() - 1;
        while (b <= e) {
            if (number[b++] != number[e--]) {
                return false;
            }
        }

        return true;
    }
};

int main() {
    int n;
    cin >> n;

    bool answer = Solution().isPalindrome(n);

    cout << answer;
}