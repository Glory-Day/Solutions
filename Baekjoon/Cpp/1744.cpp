#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main() {
    int n;
    cin >> n;

    int cnt0 = 0, cnt1 = 0;
    vector<int> arr, arr2;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        
        if (input < 0) arr.push_back(input);
        else if (input > 1) arr2.push_back(input);
        else if (input == 0) cnt0++;
        else if (input == 1) cnt1++;
    }

    sort(arr.begin(), arr.end(), greater<int>());
    sort(arr2.begin(), arr2.end());

    int answer = 0;

    int len = arr.size() - 1;
    while (arr.size() >= 2) {
        int a = arr[len];
        int b = arr[len - 1];

        answer += a * b;

        len -= 2;
        arr.pop_back();
        arr.pop_back();
    }

    len = arr2.size() - 1;
    while (arr2.size() >= 2) {
        int a = arr2[len];
        int b = arr2[len - 1];

        answer += a * b;

        len -= 2;
        arr2.pop_back();
        arr2.pop_back();
    }

    while (cnt0 != 0 && !arr.empty()) {
        arr.pop_back();
    }

    for (int& i: arr) answer += i;
    for (int& i: arr2) answer += i;

    cout << answer + cnt1;
}