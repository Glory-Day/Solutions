#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

typedef pair<bool, string> pbs;

int main() {
    string input;
    getline(cin, input);

    bool chk = false;
    string tmp = "";
    vector<string> answer;
    for (int i = 0; i < input.size(); i++) {
        if (input[i] == '<' || input[i] == '>' || input[i] == ' ') {
            if (input[i] == '<') {
                chk = true;
                reverse(tmp.begin(), tmp.end());
                answer.push_back(tmp);
                tmp.clear();
                tmp.push_back(input[i]);
            }
            else if (input[i] == '>') {
                chk = false;
                tmp.push_back(input[i]);
                answer.push_back(tmp);
                tmp.clear();
            }
            else {
                if (chk) {
                    tmp.push_back(input[i]);
                }
                else {
                    reverse(tmp.begin(), tmp.end());
                    tmp.push_back(input[i]);
                    answer.push_back(tmp);
                    tmp.clear();
                }
            }
        }
        else {
            tmp.push_back(input[i]);
        }
    }

    if (tmp.front() == '<') {
        answer.push_back(tmp);
    }
    else {
        reverse(tmp.begin(), tmp.end());
        answer.push_back(tmp);
    }

    for (auto& i: answer) {
        cout << i;
    }
}