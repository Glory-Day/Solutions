#include <iostream>
#include <vector>
#include <algorithm>

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

    int answer = 0;
    for (int i = 0; i < n; i++) {
        int mx = 0;
        for (int j = i + 1; j < n; j++) {
            if (arr[i] < arr[j]) {
                break;
            }
            mx++;
        }
        answer = max(mx, answer);
    }

    cout << answer;
}