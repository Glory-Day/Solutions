#include <iostream>
#include <map>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int answer = 0;

        int mx = 0;
        map<char, int> mp;
        for (int i = 0; i < s.size(); i++) {
            if (mp.find(s[i]) != mp.end()) {
                mx = max(mx, mp[s[i]] + 1);
            }

            mp[s[i]] = i;
            answer = max(answer, i - mx + 1);
        }

        return answer;
    }
};

int main() {
    string s;
    cin >> s;

    int answer = Solution().lengthOfLongestSubstring(s);

    cout << answer;
}