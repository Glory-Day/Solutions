#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string s;
    cin >> s;

    vector<int> nums;
    vector<char> ops;
    string num = "";
    for (char& i: s) {
        if ('0' <= i && i <= '9') {
            num += i;
        }
        else {
            ops.push_back(i);
            nums.push_back(stoi(num));
            num.clear();
        }
    }

    nums.push_back(stoi(num));

    auto it1 = nums.begin();
    auto it2 = ops.begin();

    while (it2 != ops.end()) {
        if (*it2 == '+') {
            int a = *it1, b = *(it1 + 1);
            int sum = a + b;
            it1 = nums.erase(nums.erase(it1));
            nums.insert(it1, sum);
            it2 = ops.erase(it2);
        }
        else {
            it1++;
            it2++;
        }
    }

    it1 = nums.begin();
    it2 = ops.begin();
    while(!ops.empty()) {
        int a = *it1, b = *(it1 + 1);
        int sum = a - b;
        it1 = nums.erase(nums.erase(it1));
        nums.insert(it1, sum);
        it2 = ops.erase(it2);
    }

    cout << nums[0];
}