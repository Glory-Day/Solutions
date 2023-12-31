#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string answer = "";

        int mn = 201;
        for (int i = 0; i < strs.size(); i++) {
            mn = min(mn, (int)strs[i].size());
        }

        bool check = true;
        for (int i = 0; i < mn && check; i++) {
            answer.push_back(strs[0][i]);
            for (int j = 0; j < strs.size(); j++) {
                if (answer.back() != strs[j][i]) {
                    answer.pop_back();
                    check = false;
                    break;
                }
            }
        }

        return answer;
    }
};

int main() {
    int n;
    cin >> n;

    vector<string> strs;
    for (int i = 0; i < n; i++) {
        string input;
        cin >> input;
        strs.push_back(input);
    }

    string answer = Solution().longestCommonPrefix(strs);

    cout << answer;
}