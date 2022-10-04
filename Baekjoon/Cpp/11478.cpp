#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
    string s;
    cin >> s;

    set<string> st;
    for (int i = 1; i <= s.size(); i++) {
        for (int j = 0; j <= s.size() - i; j++) {
            st.insert(s.substr(j, i));
        }
    }

    cout << st.size();
}