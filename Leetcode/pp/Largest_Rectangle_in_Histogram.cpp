#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stk;
        stk.push(-1);
        heights.push_back(-1);

        int answer = 0;
        for (int i = 0; i < heights.size(); i++) {
            while (stk.size() > 1 && heights[i] < heights[stk.top()]) {
                int mid = stk.top();
                stk.pop();

                int l = stk.top();
                answer = max(answer, (i - l - 1) * heights[mid]);
            }

            stk.push(i);
        }

        return answer;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> heights;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        heights.push_back(input);
    }

    int answer = Solution().largestRectangleArea(heights);

    cout << answer;
}