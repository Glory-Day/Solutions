#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    string input;
    cin >> input;

    stack<char> stk;
    string answer = "";
    for (int i = 0; i < input.size(); i++) {
        if (input[i] >= 'A' && input[i] <= 'Z') {
            answer.push_back(input[i]);
        }
        else {
            if (input[i] == '(') {
                stk.push(input[i]);
            }
            else if (input[i] == '*' || input[i] == '/') {
                while (stk.empty() == false && (stk.top() == '*' || stk.top() == '/')) {
                    answer.push_back(stk.top());
                    stk.pop();
                }

                stk.push(input[i]);
            }
            else if (input[i] == '+' || input[i] == '-') {
                while (stk.empty() == false && stk.top() != '(') {
                    answer.push_back(stk.top());
                    stk.pop();
                }

                stk.push(input[i]);
            }
            else if (input[i] == ')') {
                while (stk.empty() == false && stk.top() != '(') {
                    answer.push_back(stk.top());
                    stk.pop();
                }

                stk.pop();
            }
        }
    }
    
    while (stk.empty() == false) {
        answer.push_back(stk.top());
        stk.pop();
    }

    cout << answer;
}