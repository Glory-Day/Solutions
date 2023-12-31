#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

typedef long long ll;

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

    ll answer = 0;
    for (int i = 0; i < n; i++) {
        int tmp = arr[i] - i;
        answer += (tmp < 0) ? 0 : tmp;
    }

    cout << answer;
}