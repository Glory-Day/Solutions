#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <functional>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<string> arr;
    for (int i = 0; i < n; i++) {
        string input;
        cin >> input;
        arr.push_back(input);
    }

    set<int> st;
    vector<string> subs;
    function<void(string&, int)> dfs = [&](string& num, int level) {
        int size = num.size();
        if (level == size) {
            int sum = 0;
            for (auto& sub: subs) {
                sum += stoi(sub);
            }

            st.insert(sum);
        }
        
        for (int j = size - 1; j >= level; j--) {
            string tmp = num.substr(level, j - level + 1);
            subs.push_back(tmp);
            dfs(num, j + 1);
            subs.pop_back();
        }
    };

    vector<int> checks;
    int answer = 0;
    for (int i = 0; i < arr.size(); i++) {
        int size = arr[i].size();
        bool chk = true;
        for (int k = 0; k < size; k++) {
            if (arr[i][k] - '0' >= 2) {
                chk = false;
                break;
            }
        }

        if (chk) {
            cout << "Hello, BOJ 2023!\n";
            continue;
        }

        dfs(arr[i], 0);

        int j = 1;
        long long mx = *(--st.end());
        while (true) {
            long long sum = 0;
            for (int k = 0; k < arr[i].size(); k++) {
                sum += pow(arr[i][k] - '0', j);
            }

            if (sum > mx) {
                break;
            }

            if (st.find(sum) != st.end()) {
                answer++;
            }

            j++;
        }

        cout << answer << '\n';

        st.clear();
        answer = 0;
    }
}