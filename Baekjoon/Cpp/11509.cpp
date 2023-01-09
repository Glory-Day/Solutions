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

    vector<vector<int>> arrs;
    for (int i = 0; i < n; i++) {
        if (arr[i] == -1) {
            continue;
        }

        vector<int> tmp = { arr[i] };
        for (int j = i + 1; j < n; j++) {
            if (tmp.back() - 1 == arr[j]) {
                tmp.push_back(arr[j]);
                arr[j] = -1;
            }
        }
        arrs.push_back(tmp);
    }

    int answer = arrs.size();

    cout << answer;
}