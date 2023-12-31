#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
    ll n;
    cin >> n;

    int m;
    cin >> m;
    
    vector<int> times;
    for (int i = 0; i < m; i++) {
        int input;
        cin >> input;
        times.push_back(input);
    }

    ll answer = 0;

    sort(times.begin(), times.end());

    ll b = 1, e = (ll)times.back() * n, mid;
    while (b <= e) {
        ll cnt = 0;
        mid = (b + e) / 2;

        for (int i = 0; i < times.size(); i++) {
            cnt += mid / times[i];
        }

        if (cnt < n) b = mid + 1;
        else {
            if (mid <= e) answer = mid;
            e = mid - 1;
        }
    }

    cout << answer;
}