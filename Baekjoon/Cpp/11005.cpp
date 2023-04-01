#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n, b;
    cin >> n >> b;

    string answer = "";
    while (n) {
        char tmp = (n % b < 10) ? (n % b) + '0' : 'A' + ((n % b) - 10);
        n /= b;

        answer.push_back(tmp);
    }

    reverse(answer.begin(), answer.end());

    cout << answer;
}