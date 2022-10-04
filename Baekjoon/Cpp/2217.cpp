#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        arr.push_back(input);
    }

    sort(arr.begin(), arr.end(), greater<int>());

    int answer = 0;
    while(!arr.empty()) {
        answer = max(answer, arr.back() * (int)arr.size());
        arr.pop_back();
    }

    cout << answer;
}