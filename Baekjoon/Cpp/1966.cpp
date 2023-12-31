#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int m, k;
        cin >> m >> k;

        queue<pii> q;
        vector<int> v;
        for (int j = 0; j < m; j++) {
            int input;
            cin >> input;
            q.push({ input,j });
            v.push_back(input);
        }

        sort(v.begin(), v.end());

        int j = 1;
        while (!v.empty()) {
            while (v.back() != q.front().first) {
                q.push(q.front());
                q.pop();
            }

            if (q.front().second == k) {
                cout << j << '\n';
                break;
            }

            q.pop();
            v.pop_back();
            j++;
        }
    }
}