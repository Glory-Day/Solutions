#include <iostream>

using namespace std;

typedef long long ll;

/*
    문제 설명: 1분 길이의 노래 a개와 2분 길이의 노래 b개, 3분 길이의 노래 c개가 있다.
    두 콘서트에서 노래의 합의 차이가 최소가 되게 하라.

    풀이: 모든 노래의 합을 구한 다음 이를 나눌 때 짝수인 경우 나머지가 없지만,
    홀수일 경우에는 나머지가 1이 생긴다. 따라서 최소의 차이는 a + (b * 2) + (c * 3)) % 2가 된다.
*/

int main() {
    int t;
    cin >> t;

    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        cout << (a + (b * 2ll) + (c * 3ll)) % 2ll << '\n';
    }
}