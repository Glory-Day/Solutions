#include <iostream>
#include <climits>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int cnts[1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, cnt = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;

        cnts[input]++;
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < 1001; i++) {
        if (cnts[i]) pq.push(i);
    }

    if (pq.size() == 1) {
        for (int i = 0; i < cnts[pq.top()]; i++) {
            cout << pq.top() << ' ';
        }
    }
    else {
        int prev = INT_MIN;
        while (pq.size() > 2) {
            int q = pq.top();
            pq.pop();

            if (prev + 1 == q) {
                int nq = pq.top();

                cout << nq << ' ';

                cnts[nq]--;
                prev = nq;

                if (!cnts[nq]) pq.pop();

                pq.push(q);
            }
            else {
                while (cnts[q]--) cout << q << ' ';

                prev = q;
            }
        }

        int q = pq.top();
        pq.pop();

        int nq = pq.top();
        if (q + 1 == nq) {
            while (cnts[nq]--) cout << nq << ' ';
            while (cnts[q]--) cout << q << ' ';
        }
        else {
            if (prev + 1 == q) {
                cout << nq << ' ';
                cnts[nq]--;
            }

            while (cnts[q]--) cout << q << ' ';
            while (cnts[nq]--) cout << nq << ' ';
        }
    }
}