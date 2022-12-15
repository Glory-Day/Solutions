#include <iostream>

using namespace std;

int main() {
    int a, b, c, m;
    cin >> a >> b >> c >> m;

    int tmp = 0;
    int answer = 0;
    for (int i = 0; i < 24; i++) {
        if (tmp + a <= m) {
            tmp += a;
            answer += b;
        }
        else {
            tmp = (tmp - c < 0) ? 0 : tmp - c;
        }
    }

    cout << answer;
}