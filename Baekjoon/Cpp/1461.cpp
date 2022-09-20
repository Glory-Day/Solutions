#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> arr;
    arr.push_back(0);
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        arr.push_back(input);
    }

    sort(arr.begin(), arr.end());

    int tmp = 0;
    for (int i = 0; i <= n; i++) {
        if (arr[i] == 0) {
            tmp = i;
            break;
        }
    }

    int answer = 0;
    for (int i = 0; i < tmp; i += m) {
        answer += abs(arr[i] * 2);
    }

    for (int i = n; i > tmp; i -= m) {
        answer += arr[i] * 2;
    }

    answer -= max(abs(arr[0]), abs(arr[n]));

    cout << answer;
}