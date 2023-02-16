#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> getTable(string s) {
    vector<int> table(s.size(), 0);

    int j = 0;
    for (int i = 1; i < table.size(); i++) {
        while (j > 0 && s[i] != s[j]) {
            j = table[j - 1];
        }

        if (s[i] == s[j]) {
            table[i] = ++j;
        }
    }

    return table;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<int> answer;
    while (true) {
        string input;
        cin >> input;

        if (input == ".") {
            break;
        }

        vector<int> table = getTable(input);
        int tmp = input.size() - table[input.size() - 1];
        if (input.size() % tmp) {
            answer.push_back(1);
        }
        else {
            answer.push_back(input.size() / tmp);
        }
    }

    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << '\n';
    }
}