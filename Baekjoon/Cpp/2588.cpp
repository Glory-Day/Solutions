#include <iostream>
#include <string>

using namespace std;

int main() {
    int a;
    string b;
    cin >> a >> b;
    cout << a * (b[2] - '0') << '\n';
    cout << a * (b[1] - '0') << '\n';
    cout << a * (b[0] - '0') << '\n';
    cout << a * stoi(b);
}