#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

typedef pair<pair<int, int>, int> ppiii;

bool cmp(const ppiii& a, const ppiii& b) {
    if (a.first.second == b.first.second) {
        if (a.first.first == b.first.first) {
            return a.second < b.second;
        }
    
        return a.first.first < b.first.first;
    }

    return a.first.second < b.first.second;
}

int cache[2001];

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<ppiii> arr;
    for (int i = 0; i < k; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        arr.push_back({ { a,b },c });
    }

    sort(arr.begin(), arr.end(), cmp);

    int answer = 0;
    for (int i = 0; i < k; i++) {
        int mx = 0;
        for (int j = arr[i].first.first; j < arr[i].first.second; j++) {
            mx = max(mx, cache[j]);
        }

        int mn = min(arr[i].second, m - mx);
        for (int j = arr[i].first.first; j < arr[i].first.second; j++) {
            cache[j] += mn;
        }

        answer += mn;
    }

    cout << answer;
}