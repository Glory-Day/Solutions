#include <iostream>
#include <climits>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
    문제 설명: 문자열에서 문자 종류 중 하나를 지워서 회문을 만는다.
    이때 가장 적게 문자를 자운 횟수를 출력하는 문제이다.
    
    풀이: 먼저 문자열에서 문자의 종류를 배열에 저장한다.
    문자 종류별로 두 포인터를 사용한다.
    b는 문자열의 가장 앞의 번호(b = 0)이고, e는 문자열의 가장 뒤의 번호(e = n - 1)이다.
    b, e를 움직이는 조건은 다음과 같다.
    (1) 만약 문자열 S에서 S[b]와 S[e]가 같을 경우, 이는 회문의 조건을 만족함으로 아무 문자도 지울 필요가 없다.
        그리고 b를 앞으로 한 칸, e를 뒤로 한 칸 움직인다.
    (2) 문자열 S에서 S[b]와 S[e]가 다를 경우
        (1) S[b]가 선택한 문자와 같은 경우 S[b]를 지우고 b를 앞으로 한 칸 움직인다.
        (2) S[e]가 선택한 문자와 같은 경우 S[e]를 지우고 e를 뒤로 한 칸 움직인다.
        (3) S[b]와 S[e]가 선택한 문자와 다를 경우 회문을 만들 수 없음으로 종료한다.
    위 조건을 배열에 저장된 문자 개수만큼 반복하고 지운 문자의 개수를 앞에 저장된 문자와 비교해서 최솟값을 저장한다.
*/

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        bool chks[26];
        vector<char> cs;
        for (char& i: s) chks[i - 'a'] = true;
        for (int i = 0; i < n; i++) {
            if (chks[s[i] - 'a']) {
                cs.push_back(s[i]);
                chks[s[i] - 'a'] = false;
            }
        }

        int answer = INT_MAX;
        for (char& i: cs) {
            int mx = 0;
            int b = 0, e = n - 1;
            while (b <= e) {
                char l = s[b], r = s[e];
                if (l != r) {
                    if (l == i) b++, mx++;
                    else if (r == i) e--, mx++;
                    else {
                        mx = INT_MAX;
                        break;
                    }
                }
                else {
                    b++, e--;
                }
            }

            answer = min(answer, mx);
        }

        cout << ((answer == INT_MAX) ? -1 : answer) << '\n';
    }
}