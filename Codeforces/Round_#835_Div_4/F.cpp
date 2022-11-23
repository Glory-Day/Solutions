#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

typedef long long ll;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, d;
        ll c;
        cin >> n >> c >> d;

        vector<ll> arr;
        for (int i = 0; i < n; i++) {
            int input;
            cin >> input;
            arr.push_back(input);
        }

        sort(arr.begin(), arr.end(), greater<ll>());

        int b = 0, e = d + 2;
        while (b < e) {
            int mid = b + (e - b + 1) / 2;
            ll sum = 0;
            for (int i = 0; i < d; i++) {
                if (i % mid < n) {
                    sum += arr[i % mid];
                }
            }

            if (sum >= c) {
                b = mid;
            }           
            else {
                e = mid - 1;
            }
        }

        if (b == d + 2) {
            cout << "Infinity\n";
        }
        else if (b == 0) {
            cout << "Impossible\n";
        }
        else {
            cout << b - 1 << '\n';
        }
    }
}