#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        return haystack.find(needle);
    }
};

int main()
{
    string haystack, needle;
    cin >> haystack >> needle;

    int answer = Solution().strStr(haystack, needle);

    cout << answer;

    return 0;
}