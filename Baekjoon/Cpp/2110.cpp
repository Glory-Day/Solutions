#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, c;
    cin >> n >> c;

    vector<int> v;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        v.push_back(input);
    }

    sort(v.begin(), v.end());

    int b = 1, e = v.back(), answer = 0;
    while(b <= e) {
        int mid = (b + e) / 2;
        int cnt = 1;

        for (int i = 1, j = v[0]; i < n; i++) {
            if (v[i] - j >= mid) {
                j = v[i];
                cnt++;
            }
        }

        if (cnt >= c) {
            if (answer < mid) {
                answer = mid;
            }
            b = mid + 1;
        }
        else {
            e = mid - 1;
        }
    }

    cout << answer;
}