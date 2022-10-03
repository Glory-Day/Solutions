#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> v;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        v.push_back(input);
    }

    sort(v.begin(), v.end());

    int sum = 0;
    for (int& i: v) {
        sum += i;
    }

    int answer = sum;
    for (int i = n - 1; i >= 1; i--) {
        sum -= v[i];
        answer += sum;
    }

    cout << answer;
}