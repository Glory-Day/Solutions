#include <iostream>
#include <string>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    string answer = "Error";
    if (a + b + c == 180) {
        if (a == b && b == c) {
            answer = "Equilateral";
        }
        else if (a == b || b == c || c == a) {
            answer = "Isosceles";
        }
        else {
            answer = "Scalene";
        }
    }

    cout << answer;
}