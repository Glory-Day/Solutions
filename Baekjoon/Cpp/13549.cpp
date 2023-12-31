#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <functional>

using namespace std;

typedef pair<int, int> pii;

bool visited[100001];

bool check(int n) {
    return 0 <= n && n <= 100000;
}

int main() {
    int n, k;
    cin >> n >> k;

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({ 0,n });
    visited[n] = true;

    int answer = 0;
    while (!pq.empty()) {
        pii nd = pq.top();
        pq.pop();

        if (nd.second == k) {
            answer = nd.first;
            break;
        }

        for (int i = 0; i < 3; i++) {
            int nnd = 0;
            switch (i) {
                case 0:
                    nnd = nd.second * 2;
                    break;
                case 1:
                    nnd = nd.second + 1;
                    break;
                case 2:
                    nnd = nd.second - 1;
                    break;
            }

            if (check(nnd) && !visited[nnd]) {
                if (i == 0) {
                    pq.push({ nd.first,nnd });
                    visited[nnd] = true;
                }
                else {
                    pq.push({ nd.first + 1,nnd });
                    visited[nnd] = true;
                }
            }
        }
    }

    cout << answer;
}