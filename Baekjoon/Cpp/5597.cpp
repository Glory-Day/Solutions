#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    set<int> st;
    for (int i = 1; i <= 30; i++) {
        st.insert(i);
    }

    vector<int> answer;
    for (int i = 0; i < 28; i++) {
        int input;
        cin >> input;
        st.erase(input);
    }

    for (auto it = st.begin(); it != st.end(); it++) {
        cout << *it << '\n';
    }
}