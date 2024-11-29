#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> parentheses;

    void generate(string line, int left, int right)
    {
        if (left == 0 && right == 0)
        {
            parentheses.push_back(line);

            return;
        }

        if (left > 0)
        {
            generate(line + "(", left - 1, right);
        }
        
        if (right > left)
        {
            generate(line + ")", left, right - 1);
        }
    }

    vector<string> generateParenthesis(int n) {
        generate("(", n - 1, n);

        return parentheses;
    }
};

int main()
{
    int n;
    cin >> n;

    vector<string> answer = Solution().generateParenthesis(n);

    for (int i = 0; i < (int)answer.size(); i++)
    {
        cout << answer[i] << '\n';
    }

    return 0;
}