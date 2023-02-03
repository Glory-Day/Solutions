#include <iostream>
#include <string>
#include <set>
#include <stack>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

typedef pair<int, int> pii;

int main() {
    string input;
    cin >> input;

    stack<int> sk;
    vector<pii> arr;
    for (int i = 0; i < input.size(); i++) {
        if (input[i] == '(') {
            sk.push(i);
        }
        else if (input[i] == ')') {
            int tmp = sk.top();
            sk.pop();

            arr.push_back({ tmp,i });
        }
    }

    set<string> st;
    vector<bool> visited(input.size(), false);
    function<void(int, int)> dfs = [&](int i, int lv) {
        if (lv > 0) {
            string tmp = "";
            for (int j = 0; j < visited.size(); j++) {
                if (visited[j]) {
                    continue;
                }
                else {
                    tmp += input[j];
                }
            }

            st.insert(tmp);
        }

        for (int j = i; j < arr.size(); j++) {
            if (visited[arr[j].first] && visited[arr[j].second]) {
                continue;
            }

            visited[arr[j].first] = visited[arr[j].second] = true;
            dfs(j, lv + 1);
            visited[arr[j].first] = visited[arr[j].second] = false;
        }
    };

    dfs(0, 0);

    for (auto it = st.begin(); it != st.end(); it++) {
        cout << *it << '\n';
    }
}