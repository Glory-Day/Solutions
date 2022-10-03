#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string s;
    cin >> s;
    s += 'E';

    string answer = "";
    string tmp = "";
    for (auto& i: s) {
        if (i == 'X') {
            tmp += 'X';
        }
        else {
            if (!tmp.empty()) {
                if (tmp.size() % 4 == 0) {
                    for (int i = 0; i < tmp.size(); i++) {
                        answer += 'A';
                    }
                }
                else if (tmp.size() % 2 == 0) {
                    for (int i = 0; i < tmp.size() - 2; i++) {
                        answer += 'A';
                    }
                    answer += "BB";
                }
                else {
                    cout << -1;
                    return 0;
                }
            }

            answer += '.';
            tmp.clear();
        }
    }

    answer.pop_back();
    cout << answer;
}