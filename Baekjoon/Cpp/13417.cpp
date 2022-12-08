#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        deque<char> answer;
        
        char input;
        cin >> input;
        answer.push_back(input);

        char tmp = input;
        for (int i = 0; i < n - 1; i++) {
            cin >> input;
            if (tmp >= input) {
                answer.push_front(input);
                tmp = input;
            }
            else {
                answer.push_back(input);
            }
        }

        for (int i = 0; i < n; i++) {
            cout << answer[i];
        }

        cout << '\n';
    }
}