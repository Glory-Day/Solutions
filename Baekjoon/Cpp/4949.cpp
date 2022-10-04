#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    while (true) {
        string s;
        getline(cin, s);

        if (s == ".") break;

        bool check = true;
        vector<char> v;
        for (char& i: s) {
            if (i == '(' || i == '[') {
                v.push_back(i);
            }
            else {
                switch (i) {
                    case ')':
                        if (v.empty() || v.back() != '(') {
                            check = false;
                        }
                        else {
                            v.pop_back();
                        }
                        break;
                    case ']':
                        if (v.empty() || v.back() != '[') {
                            check = false;
                        }
                        else {
                            v.pop_back();
                        }
                        break;
                    default: break;
                }

                if (!check) break;
            }
        }

        if (check && v.empty()) {
            cout << "yes\n";
        }
        else {
            cout << "no\n";
        }
    }
}