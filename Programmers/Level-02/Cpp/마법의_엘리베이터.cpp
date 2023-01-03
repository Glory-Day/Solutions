#include <iostream>
#include <climits>
#include <memory.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int storey) {
    int answer = 0;

    int chk = 0;
    string s = to_string(storey);
    for (int i = s.size() - 1; i >= 0; i--) {
        int tmp = s[i] - '0' + chk;
        if (tmp >= 5) {
            if (tmp > 5) {
                answer += (10 - tmp);
                chk = 1;
                continue;
            }

            if (i != 0 && s[i - 1] >= '5') {
                chk = 1;
            }
            else {
                chk = 0;
            }

            answer += tmp;
        }
        else {
            answer += tmp;
            chk = 0;
        }
    }

    if (chk) {
        answer++;
    }

    return answer;
}

int main() {
    int storey;
    cin >> storey;

    int answer = solution(storey);

    cout << answer;
}