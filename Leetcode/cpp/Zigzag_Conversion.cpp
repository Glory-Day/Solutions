#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        string answer = "";
        
        if (numRows == 1) {
            return s;
        }

        int p = 2 * numRows - 2;
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; i + j < s.size(); j += p) {
                answer += s[i + j];

                if (i != 0 && i != numRows - 1 && j + p - i < s.size()) {
                    answer += s[j + p - i];
                }
            }
        }

        return answer;
    }
};

int main() {
    string s;
    cin >> s;

    int numRows;
    cin >> numRows;

    string answer = Solution().convert(s, numRows);

    cout << answer;
}