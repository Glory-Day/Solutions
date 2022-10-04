#include <iostream>

using namespace std;

int main() {
    int n, m, l;
    cin >> n >> m >> l;

    int b = 0, e = m - 1;
    int answer = 0;
    for (int i = 0; i < l; i++) {
        int input;
        cin >> input;

        int tmp = input - 1;
        if (tmp > e) {
            answer += tmp - e;
            e = tmp;
            b = tmp - (m - 1);
        }
        else if (tmp < b) {
            answer += b - tmp;
            b = tmp;
            e = tmp + (m - 1);
        }
    }

    cout << answer;
}