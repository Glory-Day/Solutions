#include <iostream>
#include <string>

using namespace std;

int main() {
    string a, b;
    cin >> a >> b;

    string tmp = "";
    for (int i = 0; i < a.size(); i++) {
        tmp += a[i];
        if (tmp.size() >= b.size() && tmp.substr(tmp.size() - b.size(), b.size()) == b) {
            tmp.erase(tmp.end() - b.size(), tmp.end());
        }
    }

    string answer = tmp.empty() ? "FRULA" : tmp;

    cout << answer << '\n';
}