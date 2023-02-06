#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

int main() {
    int n;
    cin >> n;

    int rt;
    vector<int> rts(51, -1);
    vector<int> map[51];
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;

        if (input != -1) {
            map[input].push_back(i);
            rts[i] = input;
        }
        else {
            rt = i;
        }
    }

    int m;
    cin >> m;

    auto bfs = [&](int b) {
        if (map[b].empty()) {
            return 0;
        }

        queue<int> q;
        q.push(b);

        int cnt = 0;
        while (!q.empty()) {
            int nd = q.front();
            q.pop();

            if (map[nd].empty()) {
                cnt++;
                continue;
            }

            for (auto& i: map[nd]) {
                q.push(i);
            }
        }

        return cnt;
    };

    map[rts[m]].erase(remove(map[rts[m]].begin(), map[rts[m]].end(), m), map[rts[m]].end());

    int answer;
    if (m == rt) {
        answer = 0;
    }
    else if (map[rt].empty()) {
        answer = 1;
    }
    else {
        answer = bfs(rt);
    }

    cout << answer;
}