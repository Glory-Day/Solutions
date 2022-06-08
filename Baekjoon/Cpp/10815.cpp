#include <iostream>
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
        int input;
        cin >> input;
        st.insert(input);
    }

    cin >> n;

    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        cout << (st.find(input) != st.end()) << ' ';
    }
}