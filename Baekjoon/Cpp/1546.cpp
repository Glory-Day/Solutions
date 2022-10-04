#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<double> nums;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        nums.push_back(input);
    }

    sort(nums.begin(), nums.end());

    double m = nums.back(), sum = 0;
    for (int i = 0; i < nums.size(); i++) {
        sum += (nums[i] / m) * 100;
    }

    cout.precision(4);
    cout << sum / (double)nums.size();
}