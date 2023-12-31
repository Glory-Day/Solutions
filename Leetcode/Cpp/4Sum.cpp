#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

class Solution {
private:
    vector<vector<int>> twoSum(vector<int>& nums, int start, int target) {
        vector<vector<int>> sets;

        int end = nums.size() - 1;
        while (start < end) {
            int sum = nums[start] + nums[end];
            if (target == sum) {
                sets.push_back({ nums[start++],nums[end--] });
                while (start < end && nums[start - 1] == nums[start]) {
                    start++;
                }
            }
            else if (target < sum) {
                end--;
            }
            else {
                start++;
            }
        }

        return sets;
    }

    vector<vector<int>> kSum(vector<int>& nums, int start, ll target, int k) {
        vector<vector<int>> sets;

        if (start == nums.size() || (ll)k * (ll)nums[start] > target || (ll)k * (ll)nums.back() < target) {
            return sets;
        }

        if (k == 2) {
            return twoSum(nums, start, target);
        }

        for (int i = start; i < nums.size(); i++) {
            if (i != start && nums[i - 1] == nums[i]) {
                continue;
            }

            for (auto& set: kSum(nums, i + 1, target - nums[i], k - 1)) {
                vector<int> temp = { nums[i] };
                for (int j = 0; j < set.size(); j++) {
                    temp.push_back(set[j]);
                }

                sets.push_back(temp);
            }
        }

        return sets;
    }
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> answer;

        sort(nums.begin(), nums.end());

        answer = kSum(nums, 0, target, 4);

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

    vector<vector<int>> answer = Solution().fourSum(nums, target);

    for (auto& i: answer) {
        for (auto& j: i) {
            cout << j << ' ';
        }
        cout << '\n';
    }
}