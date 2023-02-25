#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

typedef pair<int, int> pii;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

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
    pii tmp = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i].first <= tmp.second && tmp.second < arr[i].second) {
            tmp.second = max(tmp.second, arr[i].second);
        }
        else if (arr[i].first > tmp.second) {
            answer += tmp.second - tmp.first;
            tmp = arr[i];
        }
    }
    
    answer += tmp.second - tmp.first;

    cout << answer;
}