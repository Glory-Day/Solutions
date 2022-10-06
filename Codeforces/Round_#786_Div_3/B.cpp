#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;

/*
    문제 설명: 사전에 "ab", "ac" ~ "zy"라는 단어들이 들어있다.
    단어의 규칙은 같은 알파벳이 두번 들어갈수는 없고 각 단어는 사전순으로 저장이 되어있다.
    입력으로 들어온 단어가 사전에 몇번째에 있는지 출력한다.

    풀이: 각 단어가 두번 들어갈 수는 없으므로 "??"에서 앞의 알파벳은 26개 뒤의 알파벳은 25개 임으로 총 단어는 650개이다.
    따라서 (앞의 알파벳 번호) * 25 + (뒤의 알파벳 번호)이다.
    이때 뒤의 알파벳이 앞의 알파벳보다 작으면 원래의 목차 번호에서 1을 더해야함으로 (앞의 알파벳 번호) * 25 + (뒤의 알파벳 번호 + 1)
*/

int main() {
    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;
        
        int a = (s[0] - 'a') * 25;
        int b;
        if (s[0] < s[1]) b = s[1] - 'a';
        else if (s[0] > s[1]) b = s[1] - 'a' + 1;

        cout << a + b << '\n';
    }
}