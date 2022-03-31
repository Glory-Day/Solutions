#include <iostream>
#include <string>
#include <queue>
#include <utility>

using namespace std;

typedef pair<int, string> pis;

string direction = "DSLR";
bool visited[10000];

string bfs(int b, int e) {
    string ps;
    queue<pis> q;
    q.push({ b,"" });

    visited[b] = true;

    while (!q.empty()) {
        pis nd = q.front();

        q.pop();

        if (nd.first == e) {
            ps = nd.second;
            break;
        }

        for (char& i: direction) {
            int nnd = 0;

            switch (i) {
                case 'D':
                    nnd = (nd.first * 2) % 10000;
                    break;
                case 'S': 
                    nnd = (nd.first == 0) ? 9999 : nd.first - 1;
                    break;
                case 'L': 
                    nnd = (nd.first % 1000) * 10 + (nd.first / 1000);
                    break;
                case 'R': 
                    nnd = (nd.first % 10) * 1000 + (nd.first / 10);
                    break;
            }

            if (!visited[nnd]) {
                visited[nnd] = true;
                q.push({ nnd,nd.second + i });
            }
        }
    }

    return ps;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int a, b;
        cin >> a >> b;

        fill(visited, visited + 10000, false);

        string answer = bfs(a, b);
        cout << answer << '\n';
    }
}