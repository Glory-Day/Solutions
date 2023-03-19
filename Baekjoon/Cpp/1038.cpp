#include <iostream>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
    int n;
    cin >> n;

    queue<ll> q;
    vector<ll> answer;
    for (int i = 0; i < 10; i++) {
        q.push(i);
        answer.push_back(i);
    }

    while (!q.empty()) {
        ll nd = q.front();
        q.pop();

        for (int i = 0; i < nd % 10; i++) {
            ll tmp = nd * 10 + i;
            q.push(tmp);
            answer.push_back(tmp);
        }
    }

    if (n >= answer.size()) {
        cout << -1;
    }
    else {
        cout << answer[n];
    }
}