#include <iostream>
#include <climits>
#include <vector>

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

    vector<ll> cache(101, LONG_LONG_MAX);
    vector<int> nums = { 0,0,1,7,4,2,0,8 };
    for (int i = 0; i < 8; i++) {
        cache[i] = nums[i];
    }

    cache[6] = 6;
    cache[8] = 10;
    for (int i = 9; i <= 100; i++) {
        for (int j = 2; j <= 7; j++) {
            cache[i] = min(cache[i], cache[i - j] * 10 + nums[j]);
        }
    }

    for (int i = 0; i < n; i++) {
        string mx = "";
        int m = arr[i];
        if (m % 2 == 1) {
            m -= 3;
            mx.push_back('7');
        }

        for (int j = 0; j < m; j += 2) {
            mx.push_back('1');
        }

        ll mn = cache[arr[i]];

        cout << mn << ' ' << mx << '\n';
    }    
}