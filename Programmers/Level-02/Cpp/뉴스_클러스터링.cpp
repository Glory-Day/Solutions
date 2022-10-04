#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_map>
#include <utility>
#include <algorithm>

#define MUL 65536

using namespace std;

typedef pair<string, int> psi;

bool check(string tmp) {
    for (int i = 0; i < 2; i++) {
        if (!isalpha(tmp[i])) {
            return true;
        }
    }

    return false;
}

int solution(string str1, string str2) {
    int answer = 0;

    for (int i = 0; i < str1.size(); i++) {
        str1[i] = tolower(str1[i]);
    }

    for (int i = 0; i < str2.size(); i++) {
        str2[i] = tolower(str2[i]);
    }

    string s[2] = { str1,str2 };
    vector<string> st[2];
    for (int i = 0; i < 2; i++) {
        string tmp = "";

        for (int j = 0; j < s[i].size() - 1; j++) {
            tmp.clear();

            tmp += s[i][j];
            tmp += s[i][j + 1];

            if (check(tmp)) continue;

            st[i].push_back(tmp);
        }
    }

    sort(st[0].begin(), st[0].end());
    sort(st[1].begin(), st[1].end());

    vector<string> un = vector<string>(st[0].size() + st[1].size());
    vector<string> in = vector<string>(st[0].size() + st[1].size());

    auto iter = set_union(st[0].begin(), st[0].end(), st[1].begin(), st[1].end(), un.begin());
    un.erase(iter, un.end());

    iter = set_intersection(st[0].begin(), st[0].end(), st[1].begin(), st[1].end(), in.begin());
    in.erase(iter, in.end());

    answer = (un.size() == 0) ? MUL : (in.size() * MUL) / un.size();

    return answer;
}

int main() {
    string str1, str2;

    getline(cin, str1);
    getline(cin, str2);

    int answer = solution(str1, str2);

    cout << answer;
}