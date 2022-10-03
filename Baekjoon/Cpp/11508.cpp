#include <iostream>
#include <deque>
#include <algorithm>
#include <functional>

using namespace std;

typedef long long ll;

int main() {
    int n;
    cin >> n;

    deque<int> dq;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        dq.push_back(input);
    }

    sort(dq.begin(), dq.end(), greater<int>());

    ll answer = 0;
    while (dq.size() >= 3) {
        answer += dq[0] + dq[1];
        dq.pop_front();
        dq.pop_front(); 
        dq.pop_front();
    }

    while (!dq.empty()) {
        answer += dq.front();
        dq.pop_front();
    }

    cout << answer;
}