#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;

    int answer = 0;
    set<string> st;
    for (int i = 0 ; i < n; i++) {
        string s;
        cin >> s;

        if (s == "ENTER") {
            answer += st.size();
            st.clear();

            continue;
        }

        st.insert(s);
    }

    answer += st.size();

    cout << answer;
}