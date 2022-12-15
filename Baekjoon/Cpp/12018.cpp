#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> arr1, arr2;
    for (int i = 0; i < n; i++) {
        int p, l;
        cin >> p >> l;

        for (int j = 0; j < p; j++) {
            int input;
            cin >> input;
            arr1.push_back(input);
        }

        sort(arr1.begin(), arr1.end());

        int d = p - l;
        if (d >= 0) {
            arr2.push_back(arr1[d]);
        }
        else {
            arr2.push_back(1);
        }

        arr1.clear();
    }

    sort(arr2.begin(), arr2.end());

    int answer = 0;
    for (int i = 0; i < arr2.size(); i++) {
        m -= arr2[i];
        
        if (m < 0) {
            break;
        }
        
        answer++;
    }

    cout << answer;
}