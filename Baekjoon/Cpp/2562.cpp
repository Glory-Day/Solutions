#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int indexs[101] = { 0, };

    vector<int> nums;
    for (int i = 1; i <= 9; i++) {
        int input;
        cin >> input;
        nums.push_back(input);
        indexs[input] = i;
    }

    sort(nums.begin(), nums.end());

    cout << nums.back() << '\n' << indexs[nums.back()];
}