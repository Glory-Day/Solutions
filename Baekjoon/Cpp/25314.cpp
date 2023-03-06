#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    string answer = "int";
    for (int i = 0; i < n; i += 4) {
        answer = "long " + answer;
    }

    cout << answer;
}