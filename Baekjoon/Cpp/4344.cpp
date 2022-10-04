#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;

        vector<int> nums;
        for (int j = 0; j < m; j++) {
            int input;
            cin >> input;
            nums.push_back(input);
        }

        int sum = 0;
        for (int& k: nums) {
            sum += k;
        }

        int avg = sum / nums.size();

        sum = 0;
        for (int& k: nums) {
            sum += (k > avg) ? 1 : 0;
        }

        double rate = ((double)sum / (double)nums.size()) * 100;

        cout << fixed;
        cout.precision(3);
        cout << rate << '%' << '\n';
    }
}