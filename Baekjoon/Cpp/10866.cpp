#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main() {
    int n;
    cin >> n;

    deque<int> dq;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        if (s == "push_back") {
            int input;
            cin >> input;
            dq.push_back(input);
        }
        else if (s == "push_front") {
            int input;
            cin >> input;
            dq.push_front(input);
        }
        else if (s == "front") {
            if (dq.empty()) cout << "-1\n";
            else cout << dq.front() << '\n';
        }
        else if (s == "back") {
            if (dq.empty()) cout << "-1\n";
            else cout << dq.back() << '\n';
        }
        else if (s == "pop_back") {
            if (dq.empty()) {
                cout << "-1\n";
            }
            else {
                cout << dq.back() << '\n';
                dq.pop_back();
            }
        }
        else if (s == "pop_front") {
            if (dq.empty()) {
                cout << "-1\n";
            }
            else {
                cout << dq.front() << '\n';
                dq.pop_front();
            }
        }
        else if (s == "empty") {
            cout << dq.empty() << '\n';
        }
        else {
            cout << dq.size() << '\n';
        }
    }
}