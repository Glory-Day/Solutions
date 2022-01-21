#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int begin = 0, end = 1;
    int answer = 1;
    while (true) {
        if (begin <= n && n <= end) {
            break;
        }
        
        begin = end + 1;
        end = begin + answer * 6 - 1;
        answer++;
    }

    cout << answer;
}