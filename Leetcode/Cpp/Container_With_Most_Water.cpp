#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int answer = 0;

        int l = 0, r = height.size() - 1;
        while (l < r) {
            answer = max(answer, min(height[l], height[r]) * (r - l));

            if (height[l] < height[r]) {
                l++;
            }
            else {
                r--;
            }
        }

        return answer;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> height;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        height.push_back(input);
    }

    int answer = Solution().maxArea(height);

    cout << answer;
}