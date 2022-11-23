#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

ll calc(vector<int>& arr) {
    ll a = 0, b = 0;
    for (int i = arr.size() - 1; i >= 0; i--) {
        if (arr[i] == 0) {
            a++;
        }
        else {
            b += a;
        }
    }

    return b;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> arr;
        for (int i = 0; i < n; i++) {
            int input;
            cin >> input;
            arr.push_back(input);
        }

        ll answer = calc(arr);

        for (int i = 0; i < n; i++) {
            if (arr[i] == 0) {
                arr[i] = 1;
                answer = max(answer, calc(arr));
                arr[i] = 0;
                break;
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            if (arr[i] == 1) {
                arr[i] = 0;
                answer = max(answer, calc(arr));
                arr[i] = 1;
                break;
            }
        }

        cout << answer << '\n';
    }
}