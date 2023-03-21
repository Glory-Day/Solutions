#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    while (true) {
        int inputs[3];
        cin >> inputs[0] >> inputs[1] >> inputs[2];

        if (inputs[0] + inputs[1] + inputs[2] == 0) {
            break;
        }

        sort(inputs, inputs + 3);

        string answer = "Invalid";
        if (inputs[0] + inputs[1] > inputs[2]) {
            if (inputs[0] == inputs[1] && inputs[1] == inputs[2]) {
                answer = "Equilateral";
            }
            else if (inputs[0] == inputs[1] || inputs[1] == inputs[2] || inputs[0] == inputs[2]) {
                answer = "Isosceles";
            }
            else {
                answer = "Scalene";
            }
        }

        cout << answer << '\n';
    }
}