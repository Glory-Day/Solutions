#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int sum = 0;
    vector<int> arr;
    for (int i = 0; i < 5; i++) {
        int input;
        cin >> input;
        arr.push_back(input);
        sum += input;
    }

    sort(arr.begin(), arr.end());

    cout << sum / 5 << '\n';
    cout << arr[2];
}