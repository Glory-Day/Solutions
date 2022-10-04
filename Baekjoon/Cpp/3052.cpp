#include <iostream>
#include <string>

using namespace std;

int main() {
    int indexs[42] = { 0, };

    for (int i = 0; i < 10; i++) {
        int input;
        cin >> input;
        indexs[input % 42]++;
    }

    int answer = 0;
    for (int& i: indexs) {
        answer += (i != 0) ? 1 : 0;
    }

    cout << answer;
}