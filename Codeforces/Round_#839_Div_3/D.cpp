#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

typedef long long ll;

int arr[200001];

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
        }

        int mx = 1e9, mn = 0;
        for (int i = 1; i < n; i++) {
            if (arr[i] == arr[i + 1]) {
                continue;
            }

            if(arr[i] < arr[i + 1]) { 
                mx = (mx < arr[i] + (arr[i + 1] - arr[i]) / 2) ? mx : arr[i] + (arr[i + 1] - arr[i]) / 2;
            }
			if(arr[i] > arr[i + 1]) {
                mn = (mn > arr[i + 1] + (arr[i] - arr[i + 1] + 1) / 2) ? mn : arr[i + 1] + (arr[i] - arr[i + 1] + 1) / 2;
            }
        }

        int answer = -1;
        if (mn <= mx) {
            answer = mn;
        }

        cout << answer << '\n';
    }
}