#include <iostream>
#include <deque>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int m;
        string s1, s2;
        cin >> s1 >> m >> s2;

        string num;
        deque<int> dq;
        for (int j = 1; j < s2.size(); j++) {
            if (!num.empty() && (s2[j] == ']' || s2[j] == ',')) {
                dq.push_back(stoi(num));
                num.clear();
            }
            else {
                num += s2[j];
            }
        }

        bool flag = true, check = true;
        for (char& j: s1) {
            if (j == 'R'){
                flag = (flag ? false : true);
            }
            else {
                if (dq.empty()) {
                    check = false;
                    break;
                }
                else if (flag) {
                    dq.pop_front();
                }
                else {
                    dq.pop_back();
                }
            }
        }

        if (check) {
            cout << '[';
            if (dq.empty()) {
                cout << "]\n";
            }
            else if (flag) {
                for (int j = 0; j < dq.size() - 1; j++) {
                    cout << dq[j] << ',';
                }
                cout << dq.back() << "]\n";
            }
            else {
                for (int j = dq.size() - 1; j >= 1; j--) {
                    cout << dq[j] << ',';
                }
                cout << dq.front() << "]\n";
            }
        }
        else {
            cout << "error\n";
        }
    }
}