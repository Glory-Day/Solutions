#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int inputs[3];
    cin >> inputs[0] >> inputs[1] >> inputs[2];

    sort(inputs, inputs + 3);

    int answer = inputs[0] + inputs[1] + min(inputs[0] + inputs[1] - 1, inputs[2]);

    cout << answer;
}