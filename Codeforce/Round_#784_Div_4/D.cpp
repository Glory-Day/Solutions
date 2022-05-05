#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
    문제 풀이: 'W'로만 이루어진 문자열이 주어지고 "BR" 또는 "RB" 스탬프를 찍을 수 있다.
    알맞게 스탬프를 찍어 주어진 문자열을 만들 수 있는가를 출력한다.

    풀이: 스탬프로 만들 수 없는 문자열은 "B" 또는 "R"로만 이루어진 문자열이다. 따라서 해당 문자열이
    존재하는지 확인한다.
*/

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        vector<string> vs;
        string temp = "";
        for (int i = 0; i < n; i++) {
            if (s[i] == 'R' || s[i] == 'B') temp += s[i];
            else if (!temp.empty()) {
                vs.push_back(temp);
                temp.clear();
            }
        }

        if (!temp.empty()) {
            vs.push_back(temp);
        }

        bool check = true;
        for (auto i: vs) {
            int a = 0, b = 0;
            for (int j = 0; j < i.size(); j++) {
                if (i[j] == 'B') a++;
                else b++;
            }

            if (a == 0 || b == 0) {
                check = false;
                break;
            }
        }

        if (check) cout << "YES\n";
        else cout << "NO\n";
    }
}