#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> st;
        for (int i = 0; i < (int)nums.size(); i++)
        {
            st.insert(nums[i]);
        }

        nums.clear();

        for (auto iter = st.begin(); iter != st.end(); iter++)
        {
            nums.push_back(*iter);
        }

        return (int)st.size();
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

    int answer = Solution().removeDuplicates(nums);

    cout << answer;

    return 0;
}