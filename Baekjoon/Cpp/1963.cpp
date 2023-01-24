#include <iostream>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int t;
    cin >> t;

    vector<bool> cache(10000, true);
    for (int i = 2; i < 10000; i++) {
        if (cache[i] == false) {
            continue;
        }

        for (int j = 2; i * j < 10000; j++) {
            cache[i * j] = false;            
        }
    }

    while (t--) {
        int a, b;
        cin >> a >> b;

        queue<int> q;
        q.push(a);

        vector<int> visited(10000, -1);
        visited[a] = 0;

        while (!q.empty()) {
            int nd = q.front();
            q.pop();

            if (nd == b) {
                break;
            }

            int tmp = nd;
            int p = 1;
            while (tmp != 0) {
                int d = tmp % 10;
                int nnd;
                for (int i = 1; i <= d; i++) {
                    nnd = nd + p * -i;
                    if (nnd < 1000) {
                        break;
                    }

                    if (visited[nnd] == -1 && cache[nnd]) {
                        visited[nnd] = nd;
                        q.push(nnd);
                    }
                }

                for (int i = 1; i <= 9 - d; i++) {
                    nnd = nd + p * i;
                    if (nnd >= 10000) {
                        break;
                    }

                    if (visited[nnd] == -1 && cache[nnd]) {
                        visited[nnd] = nd;
                        q.push(nnd);
                    }
                }

                p *= 10;
                tmp /= 10;
            }
        }

        int tmp = b;
        int answer = 0;
        if (visited[tmp] == -1) {
            cout << "Impossible\n";
        }
        else {
            while (true) {
                tmp = visited[tmp];
                if (tmp == 0) {
                    break;
                }

                answer++;
            }

            cout << answer << '\n';
        }
    }
}