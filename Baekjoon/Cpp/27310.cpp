#include <iostream>
#include <string>

using namespace std;

int main() {
    string input;
    cin >> input;

    int a = 0, b = 0;
    for (int i = 0; i < input.size(); i++) {
        if (input[i] == ':') {
            a++;
        }
        else if (input[i] == '_') {
            b++;
        }
    }

    int answer = input.size() + a + b * 5;

    cout << answer;
}