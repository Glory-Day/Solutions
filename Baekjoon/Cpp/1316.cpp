#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n, answer = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        string s2 = "";
        s2 += s[0];

        int index = 0;
        for (int j = 1; j < s.size(); j++) {
            if (s2[index] != s[j]) {
                s2 += s[j];
                index++;
            }
        }

        int counts[26] = { 0, };
        for (auto j: s2) {
            counts[j - 'a']++;
        }

        bool check = true;
        for (int& j: counts) {
            if (j > 1) {
                check = false;
                break;
            }
        }

        if (check) answer++;
    }

    cout << answer;
}