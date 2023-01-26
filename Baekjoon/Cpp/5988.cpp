#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string input;
        cin >> input;

        int tmp = input.back() - '0';
        if (tmp % 2 == 0) {
            cout << "even\n";
        }
        else {
            cout << "odd\n";
        }
    }
}