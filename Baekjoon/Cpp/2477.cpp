#include <iostream>
#include <deque>
#include <algorithm>
#include <utility>

using namespace std;

typedef pair<int, int> pii;

int main() {
    int n;
    cin >> n;

    deque<pii> arr;
    int cnt[5] = { 0,0,0,0,0 };
    for (int i = 0; i < 6; i++) {
        int a, b;
        cin >> a >> b;
        arr.push_back({ a,b });
        cnt[a]++;
    }

    if (cnt[1] == 1 && cnt[3] == 1) {
        while (arr.front().first != 3) {
            arr.push_back(arr.front());
            arr.pop_front();
        }
    }
    else if (cnt[1] == 1 && cnt[4] == 1) {
        while (arr.front().first != 1) {
            arr.push_back(arr.front());
            arr.pop_front();
        }
    }
    else if (cnt[2] == 1 && cnt[3] == 1) {
        while (arr.front().first != 2) {
            arr.push_back(arr.front());
            arr.pop_front();
        }
    }
    else if (cnt[2] == 1 && cnt[4] == 1) {
        while (arr.front().first != 4) {
            arr.push_back(arr.front());
            arr.pop_front();
        }
    }

    int answer = arr[0].second * arr[1].second - arr[3].second * arr[4].second;

    cout << answer * n;
}