#include <iostream>
#include <climits>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int answer = 0;
        
        sort(nums.begin(), nums.end());
        answer = nums[0] + nums[1] + nums[2];

        int mn = INT_MAX;
        int n = nums.size();
        for (int i = 0; i < n - 2; i++) {
            int l = i + 1, r = n - 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                int d = abs(sum - target);
                if (d < mn) {
                    mn = d;
                    answer = sum;
                }

                if (sum == target) {
                    return target;
                }

                if (sum > target) {
                    r--;
                }
                else {
                    l++;
                }
            }
        }      

        return answer;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> nums;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        nums.push_back(input);
    }

    int target;
    cin >> target;

    int answer = Solution().threeSumClosest(nums, target);

    cout << answer;
}