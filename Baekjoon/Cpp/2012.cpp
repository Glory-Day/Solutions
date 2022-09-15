#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

typedef long long ll;

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

    sort(arr.begin(), arr.end());

    ll answer = 0;
    for (auto it = arr.rbegin(); it != arr.rend(); it++) {
        answer += abs(*it - n);
        n--;
    }

    cout << answer;
}