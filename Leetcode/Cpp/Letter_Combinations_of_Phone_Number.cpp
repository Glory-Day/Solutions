#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <functional>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> answer;

        if (digits.empty()) {
            return answer;
        }

        vector<string> alphabets = { "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
        map<char, string> mp;
        for (char i = '2'; i <= '9'; i++) {
            mp.insert({ i,alphabets[(i - '0') - 2] });
        }        

        string temp = "";
        function<void(int)> dfs = [&](int level) {
            if (level == digits.size()) {
                answer.push_back(temp);
            }
            
            for (auto& i: mp[digits[level]]) {
                temp.push_back(i);
                dfs(level + 1);
                temp.pop_back();
            }
        };

        dfs(0);

        return answer;
    }
};

int main() {
    string digits;
    cin >> digits;

    vector<string> answer = Solution().letterCombinations(digits);

    for (auto& i: answer) {
        cout << i << ' ';
    }
}