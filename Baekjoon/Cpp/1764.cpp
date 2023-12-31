#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    set<string> st;
    for (int i = 0; i < n; i++) {
        string input;
        cin >> input;
        st.insert(input);
    }

    vector<string> answer;
    for (int i = 0; i < m; i++) {
        string input;
        cin >> input;
        if (st.find(input) != st.end()) {
            answer.push_back(input);
        }
    }

    sort(answer.begin(), answer.end());

    cout << answer.size() << '\n';
    for (auto& i: answer) cout << i << '\n';
}