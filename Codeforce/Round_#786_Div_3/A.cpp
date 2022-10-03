#include <iostream>

using namespace std;

typedef long long ll;

/*
    문제 설명: x, y가 주어진다. x에 자연수 b를 a번 곱해서 y를 만들 수 있으면, a b를 출력하고
    없으면 0 0을 출력한다.

    풀이: y가 x보다 작으면 a b를 만들 수 없다.
    b를 (y / x)로 정하면 이는 x에 b를 1번 곱해서 y를 만들 수 있으므로 1 (y / x)로 표현할 수 있다.
    하지만, (y % x)가 0이 아니라면 x에 b를 1번 곱해서 y를 만들 수 없다.
*/

int main() {
    int t;
    cin >> t;

    while (t--) {
        int x, y;
        cin >> x >> y;

        if (x > y) 
            cout << "0 0\n";
        else {
            int n = y / x;
            int mod = y % x;

            if (mod != 0) 
                cout << "0 0\n";
            else {
                cout << 1 << ' ' << n << '\n';
            }
        }
    }
}