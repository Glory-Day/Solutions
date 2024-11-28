#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        auto iter = find(nums.begin(), nums.end(), val);
        while (iter != nums.end())
        {
            nums.erase(iter);

            iter = find(nums.begin(), nums.end(), val);
        }

        return (int)nums.size();
    }
};

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    int val;
    cin >> val;

    int answer = Solution().removeElement(nums, val);

    cout << answer;

    return 0;
}