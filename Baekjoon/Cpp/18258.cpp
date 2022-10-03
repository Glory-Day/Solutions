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
        else if (s == "front") {
            if (q.empty()) cout << "-1\n";
            else cout << q.front() << '\n';
        }
        else if (s == "back") {
            if (q.empty()) cout << "-1\n";
            else cout << q.back() << '\n';
        }
        else if (s == "pop") {
            if (q.empty()) cout << "-1\n";
            else {
                cout << q.front() << '\n';
                q.pop();
            }
        }
        else if (s == "empty") {
            cout << q.empty() << '\n';
        }
        else {
            cout << q.size() << '\n';
        }
    }
}