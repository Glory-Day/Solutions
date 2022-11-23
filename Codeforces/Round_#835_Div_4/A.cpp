#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        vector<int> arr;
        for (int i = 0; i < 3; i++) {
            int input;
            cin >> input;
            arr.push_back(input);
        }

        sort(arr.begin(), arr.end());

        cout << arr[1] << '\n';
    }
}