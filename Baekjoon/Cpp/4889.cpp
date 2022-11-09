#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    int t = 0;
    while (++t) {
        string s;
        cin >> s;

        if (s.front() == '-') {
            break;
        }

        int answer = 0;
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '}' && !st.empty() && st.top() == '{') {
                st.pop();
            }
            else {
                st.push(s[i]);
            }
        }

        while (!st.empty()) {
            char a = st.top();
            st.pop();

            char b = st.top();
            st.pop();

            if (a == b) {
                answer++;
            }
            else {
                answer += 2;
            }
        }

        cout << t << ". " << answer << '\n';
    }
}