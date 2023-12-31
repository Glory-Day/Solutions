#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    set<int> st;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        if (s == "add") {
            int input;
            cin >> input;
            st.insert(input);
        }
        else if (s == "check") {
            int input;
            cin >> input;
            bool chk = st.find(input) != st.end();
            cout << chk << '\n';
        }
        else if (s == "remove") {
            int input;
            cin >> input;
            st.erase(input);
        }
        else if (s == "toggle") {
            int input;
            cin >> input;
            if (st.find(input) != st.end()) st.erase(input);
            else st.insert(input);
        }
        else if (s == "all") {
            st = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
        }
        else {
            st.clear();
        }
    }
}