#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> v;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        if (s == "push") {
            int input;
            cin >> input;
            v.push_back(input);
        }
        else if (s == "top") {
            cout << (v.empty() ? -1 : v.back()) << '\n';
        }
        else if (s == "pop") {
            if (v.empty()) cout << -1 << '\n';
            else {
                cout << v.back() << '\n';
                v.pop_back();
            }
        }
        else if (s == "size") {
            cout << v.size() << '\n';
        }
        else {
            cout << v.empty() << '\n';
        }
    }
}