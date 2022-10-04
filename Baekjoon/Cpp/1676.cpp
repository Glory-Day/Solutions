#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int answer = 0;
    for (int i = 1; i <= n; i++) {
        int num = i;
        while (num % 5 == 0) {
            num /= 5;
            answer++;
        }
    }

    cout << answer;
}