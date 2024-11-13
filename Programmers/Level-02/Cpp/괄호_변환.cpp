#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

string checkSequence(string sequence) {
    int leftCount = 0;
    int rightCount = 0;
    
    string U = "";
    string V = "";
    
    if(sequence.empty()) return "";
    
    for(auto i : sequence) {
        if(leftCount == rightCount && leftCount != 0 && rightCount != 0) {
            V += i;
        }
        else {
            if(i == '(') {
                leftCount++;
                U += i;
            }
            else {
                rightCount++;
                U += i;
            }
        }
    }
    
    if(U.front() == ')') {
        string temp = "(";
        string changedSequence = "";
        if(U.length() > 2) {
            for(int i = 1; i < U.length() - 1; i++) {
                if(U[i] == ')') changedSequence += '(';
                else changedSequence += ')';
            }
        }
        return temp = temp + checkSequence(V) + ')' + changedSequence;
    } 
    else return U + checkSequence(V);
}

string solution(string p) {
    string answer = checkSequence(p);

    return answer;
}

int main()
{
    string p;
    cin >> p;

    string answer = solution(p);

    cout << answer;

    return 0;
}