#include <iostream>
#include <string>

using namespace std;

int main() {
    string input;
    cin >> input;

    int answer = 1;
    int b = 0, e = input.size() - 1;
    while (b < e) {
        if (input[b] != input[e]) {
            answer = 0;
            break;
        }

        b++, e--;
    }

    cout << answer;
}