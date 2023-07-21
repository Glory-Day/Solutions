#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {        
		vector<vector<int>> answers;

        sort(nums.begin(), nums.end());

		int c;
        int n = nums.size();
		for (int i = 0; i < n ; i++) {
			if (c == -nums[i]) {
				continue;
            }

			c = -nums[i];

			int l = i + 1, r = n - 1, sum = 0;
			while (l < r) {
				sum = nums[l] + nums[r];
				if (c > sum) {
					++l;
				}
				else if (c < sum) {
					--r;
				}
				else {
					vector<int> tmp = { nums[l],-c,nums[r]};
					answers.push_back(tmp);
					
					while (l < n && nums[l] == tmp[0]) {
						++l;
					}

					while (r >= 0 &&nums[r] == tmp[2]) {
						--r;
					}
				}
			}
		}
		return answers;
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

    vector<vector<int>> answer = Solution().threeSum(nums);

    for (auto& i: answer) {
        for (auto& j: i) {
            cout << j << ' ';
        }
        cout << '\n';
    }
}