#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<ll>> arr;
    for (int i = 0; i < n; i++) {
        vector<ll> inputs;
        for (int j = 0; j < 4; j++) {
            ll input;
            cin >> input;
            inputs.push_back(input);
        }
        arr.push_back(inputs);
    }

    vector<ll> cache;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cache.push_back(arr[i][2] + arr[j][3]);
        }
    }

    sort(cache.begin(), cache.end());

    ll answer = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ll mid = arr[i][0] + arr[j][1];
            ll b = lower_bound(cache.begin(), cache.end(), -mid) - cache.begin();
            ll e = upper_bound(cache.begin(), cache.end(), -mid) - cache.begin();

            if (-mid == cache[b]) {
                answer += (e - b);
            }
        }
    }

    cout << answer;
}