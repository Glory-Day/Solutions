#include <iostream>
#include <string>

using namespace std;

int main() {
    int indexs[10] = { 0, };

    int nums = 1;
    for (int i = 0; i < 3; i++) {
        int input;
        cin >> input;
        nums *= input;
    }

    string n = to_string(nums);
    for (auto i: n) {
        indexs[i - '0']++;
    }

    for (int& i: indexs) {
        cout << i << '\n';
    }
}