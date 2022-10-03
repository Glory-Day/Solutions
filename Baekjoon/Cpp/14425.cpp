#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    set<string> st;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        st.insert(s);
    }

    int answer = 0;
    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        answer += st.find(s) != st.end();
    }

    cout << answer;
}