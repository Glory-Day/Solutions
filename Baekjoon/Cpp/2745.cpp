#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string n;
    cin >> n;

    int b;
    cin >> b;

    int answer = 0;
    for (int i = n.size() - 1, j = 1; i >= 0; i--, j *= b) {
        int tmp;
        if ('A' <= n[i] && n[i] <= 'Z') {
            tmp = (n[i] - 'A') + 10;
        }
        else {
            tmp = n[i] - '0';
        }

        answer += tmp * j;
    }

    cout << answer;
}