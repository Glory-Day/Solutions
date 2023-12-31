#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int sum = 0;
    int answer = 101;

    for (int i = 0; i < 7; i++) {
        int input;
        cin >> input;
        if (input % 2 == 1) {
            sum += input;
            answer = min(answer, input);
        }
    }

    if (sum != 0) {
        cout << sum << '\n';
        cout << answer;
    }
    else {
        cout << -1;
    }
}