#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<pii> arr;
        for (int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;
            arr.push_back({ a,b });
        }

        sort(arr.begin(), arr.end());

        int answer = 0;
        int mx = arr.front().second;
        for (int i = 0; i < n; i++) {
            if (arr[i].second <= mx) {
                answer++;
                mx = arr[i].second;
            }
        }

        cout << answer << '\n';
    }
}