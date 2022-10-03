#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string s)
{
    int answer = -1;

    // Stack에 순차적으로 저장을 한다.
    vector<char> v;
    for (char& i: s) {
        // Stack이 비어있거나 Stack의 맨 위가 다음에 들어갈 문자와 다를 경우에는 Stack 공간에 넣는다.
        if (v.empty() || v.back() != i) {
            v.push_back(i);
        }
        // 아닌 경우, 문자가 서로 짝지어진 경우임으로 Stack에 맨 위를 뺀다.
        else {
            v.pop_back();
        }
    }
    
    // Stack이 비어있는 경우면 주어진 문자열에 짝지어진 문자를 전부 제거한 것이므로 1을 반환한다.
    if (v.empty()) answer = 1;
    else answer = 0;

    return answer;
}

int main() {
    string s;
    cin >> s;

    int answer = solution(s);

    cout << answer;
}