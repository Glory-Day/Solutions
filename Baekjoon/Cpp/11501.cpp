#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

bool visited[1000001];

bool cmp(pii& a, pii& b) {
    if (a.first == b.first) {
        return a.second > b.second;
    }
    return a.first > b.first;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> arr;
        vector<pii> arr2;
        for (int i = 0; i < n; i++) {
            int input;
            cin >> input;
            arr.push_back(input);
            arr2.push_back({ input,i });
        }

        sort(arr2.begin(), arr2.end(), cmp);

        ll answer = 0;
        for (int i = 0; i < n; i++) {
            for (int j = arr2[i].second; j >= 0 && !visited[j]; j--) {
                answer += arr2[i].first - arr[j];
                visited[j] = true;
            }
        }

        fill(visited, visited + 1000000, false);

        cout << answer << '\n';
    }
}