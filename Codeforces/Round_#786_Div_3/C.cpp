#include <iostream>

using namespace std;

typedef long long ll;

/*
    문제 설명: 'a'로만 이루어진 문자열 s와 소문자 알파벳으로 이루어진 문자열 t가 주어진다.
    문자열 s안에 'a' 한 글자를 문자열 t로 변환이 가능하다.
    임의의 횟수로 문자열 s를 변환할때 변화가능한 문자열의 개수를 구한다.
    이때 변환가능한 문자열의 개수가 무한대이면 -1을 출력한다.

    풀이: 문자열 t에 따라 변화가능한 문자열의 개수가 정해진다.
    (1) 문자열 t에 'a'가 1개고 다른 문자가 없을 경우: 문자열 s은 변하지 않기 때문에 변화가능한 문자열의 개수는 1개이다.
    (2) 문자열 t에 'a'가 1개 이상이고 다른 문자가 있을 경우: 변화가능한 문자열은 무한개이다.
    (3) 문자열 t에 'a'가 없고 다른 문자가 있을 경우: 변화가능한 문자는 2^(문자열 s의 길이)개이다.
*/

int main() {
    int t;
    cin >> t;

    while (t--) {
        string s, s2;
        cin >> s >> s2;

        int cnt = 0;
        for (int i = 0; i < s2.size(); i++) {
            if (s2[i] == 'a') cnt++;
        }

        ll answer = 1;
        if (cnt == 1 && s2.size() == 1) {
            cout << answer << '\n';
        }
        else if (cnt != 0 && s2.size() > 1) {
            cout << -answer << '\n';
        }
        else {
            for (int i = 0; i < s.size(); i++) {
                answer *= 2ll;
            }

            cout << answer << '\n';
        }
    }
}