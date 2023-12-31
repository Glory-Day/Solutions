#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        bool check = true;
        vector<char> v;
        for(char& j: s) {
            if (j == '(') {
                v.push_back(j);
            }
            else {
                if (v.empty()) {
                    check = false;
                    break;
                }
                else v.pop_back();
            }
        }

        if (check && v.empty()) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
}