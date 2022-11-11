#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        if (n > m) {
            nums1.swap(nums2);
            swap(n, m);
        }

        int b = 0, e = n, mid = (n + m + 1) / 2;
        while (b <= e) {
            int i = (b + e) / 2;
            int j = mid - i;

            if (i < e && nums2[j - 1] > nums1[i]) {
                b = i + 1;
            }
            else if (i > b && nums1[i - 1] > nums2[j]) {
                e = i - 1;
            }
            else {
                double l = 0, r = 0;
                if (i == 0) {
                    l = nums2[j - 1]; 
                }
                else if (j == 0) { 
                    l = nums1[i - 1];
                }
                else {
                    l = max(nums1[i - 1], nums2[j - 1]);
                }
                
                if ((n + m) % 2 == 1) {
                    return l;
                }

                if (i == n) {
                    r = nums2[j];
                }
                else if (j == m) {
                    r = nums1[i];
                }
                else {
                    r = min(nums2[j], nums1[i]);
                }

                return (l + r) / 2.0;
            }
        }

        return 0.0;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> nums1;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        nums1.push_back(input);
    }

    cin >> n;

    vector<int> nums2;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        nums2.push_back(input);
    }

    double answer = Solution().findMedianSortedArrays(nums1, nums2);

    cout << answer;
}