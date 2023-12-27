#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    stack<int> st;
    vector<int> answer;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;

        int b;
        switch (a) {
            case 1:
                cin >> b;
                st.push(b);
                break;
            case 2:
                if (st.empty()) {
                    b = -1;
                }
                else {
                    b = st.top();
                    st.pop();
                }
                answer.push_back(b);
                break;
            case 3:
                b = st.size();
                answer.push_back(b);
                break;
            case 4:
                b = st.empty();
                answer.push_back(b);
                break;
            case 5:
                b = st.empty() ? -1 : st.top();
                answer.push_back(b);
                break;
        }
    }

    for (int& i: answer) {
        cout << i << '\n';
    }
}