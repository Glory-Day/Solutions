#include <iostream>

using namespace std;

typedef long long ll;

/*
    풀이: 순열의 합을 S라고 할 때, S - 1을 만드는 순열은 그 순열에서 원소 '1'을 뺀 나머지 순열이다.
    여기서 '0'의 유무가 순열의 개수를 결정함으로 2^('0'의 개수)이다.
    따라서 S - 1을 만드는 순열의 개수는 2^('0'의 개수) * (1의 개수)이다.
*/

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        ll a = 0, b = 0;
        for (int i = 0; i < n; i++) {
            int input;
            cin >> input;

            if (input == 0) a++;
            if (input == 1) b++;
        }

        cout << (1ll << a) * b << '\n';
    }
}