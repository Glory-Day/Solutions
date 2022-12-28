#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;

    char tmp = s[0];
    int a = 0, b = 0;
    for (int i = 0; i < s.size(); i++) {
        if (tmp == s[i]) {
            a++;
        }
        else {
            b++;
        }

        if (a == b) {
            tmp = s[i + 1];
            a = b = 0;
            answer++;
        }
    }

    if (a != 0 || b != 0) {
        answer++;
    }

    return answer;
}

int main() {
    string s;
    cin >> s;

    int answer = solution(s);

    cout << answer;
}