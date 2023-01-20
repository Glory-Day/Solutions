#include <iostream>

using namespace std;

int main() {
    int e, s, m;
    cin >> e >> s >> m;

    int answer = 1;
    int a = 1, b = 1, c = 1;
    while (true) {
        if (e == a && s == b && m == c) {
            break;
        }

        a++, b++, c++, answer++;;

        if (a > 15) {
            a = 1;
        }

        if (b > 28) {
            b = 1;
        }

        if (c > 19) {
            c = 1;
        }
    }

    cout << answer;
}