#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    queue<int> q;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        if (s == "push") {
            int input;
            cin >> input;
            q.push(input);
        }
        else if (s == "pop") {
            if (!q.empty()) {
                cout << q.front() << '\n';
                q.pop();
            }
            else cout << -1 << '\n';
        }
        else if (s == "size") {
            cout << q.size() << '\n';
        }
        else if (s == "empty") {
            cout << q.empty() << '\n';
        }
        else if (s == "front") {
            int answer = (q.empty()) ? -1 : q.front();
            cout << answer << '\n';
        }
        else {
            int answer = (q.empty()) ? -1 : q.back();
            cout << answer << '\n';
        }
    }
}