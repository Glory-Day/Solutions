#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <functional>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

/*
    문제 설명: 비싼 그림이 걸려있는 방에 n명의 사람들이 차례대로 1명씩 구경을 했다.
    그리고 비싼 그림은 도둑을 맞았는데 n명 중에 범인있고 용의자를 색출해야 한다.
    방에 들어간 순서대로 심문을 하는데 3종류의 답을 들을 수 있다.
    (1) '0': 그림을 보지 못했다.
    (2) '1': 그림을 봤다.
    (3) '?': 기억이 나지 않는다.
    범인은 거짓말을 할 수 있고 나머지 사람은 진실만을 말했을때 용의자는 총 몇명인지 출력한다.

    풀이: '0', '1', '?'의 개수를 샌다.
    (1) '0', '1'의 개수가 0보다 클 경우: '1'이 마지막에 있고 '0'이 처음 나오는 그 사이의 개수가 용의자의 개수이다.
    (2) '1'이 개수가 0이고 '0'의 개수가 0보다 클 경우: 맨 뒤부터 '0'이 나올 때까지의 개수가 용의자의 개수이다.
    (3) '0'의 개수가 0이고 '1'의 개수가 0보다 클 경우:  마지막 '1'부터 맨 뒤까지 개수가 용의자의 개수이다.
    (4) '?'만 있을 경우: 사람의 총 개수가 용의자의 개수이다.
    '1' 뒤에는 '0'이 올 수가 없다. 이유는 '1'이 범인일 경우 그 뒤에 있는 '0'은 거짓이 되는거고 뒤의 사람 중 범인이 있을 경우 '1'이 거짓이 되기 때문이다.
*/

int main() {
    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        int one = 0, zero = 0, question = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '?') question++;
            else if (s[i] == '1') one++;
            else zero++;
        }

        if (one != 0 && zero != 0) {
            int len = s.size();
            for (int i = 0; i < s.size(); i++) {
                if (s[i] == '1') one--;
                if (one == 0) break;
                len--;
            }
            for (int i = s.size() - 1; i >= 0; i--) {
                if (s[i] == '0') zero--;
                if (zero == 0) break;
                len--;
            }
            cout << len << '\n';
        }
        else if (zero != 0) {
            int len = 1;
            for (int i = 0; i < s.size(); i++) {
                if (s[i] == '0') break;
                len++;
            }
            cout << len << '\n';
        }
        else if (one != 0) {
            int len = 1;
            for (int i = s.size() - 1; i >= 0; i--) {
                if (s[i] == '1') break;
                len++;
            }
            cout << len << '\n';
        }
        else {
            cout << question << '\n';
        }
    }
}