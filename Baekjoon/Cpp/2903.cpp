#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int answer = 2;
    for (int i = 0, j = 1; i < n; i++, j *= 2) {
        answer += j;
    }

    answer *= answer;
    
    cout << answer;
}