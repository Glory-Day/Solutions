#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string a, b;
    cin >> a >> b;

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    int length = min(a.size(), b.size());
    int one = 0;
    string answer = "";
    for (int i = 0; i < length; i++) {
        int c = (a[i] - '0') + (b[i] - '0') + one;
        one = c / 10;
        answer += to_string(c % 10);
    }

    if (length < a.size()) {
        for (int i = length; i < a.size(); i++) {
            int c = (a[i] - '0') + one;
            one = c / 10;
            answer += to_string(c % 10);
        }
    }
    else {
        for (int i = length; i < b.size(); i++) {
            int c = (b[i] - '0') + one;
            one = c / 10;
            answer += to_string(c % 10);
        }
    }

    answer += (one == 1) ? "1" : "";

    reverse(answer.begin(), answer.end());

    cout << answer;
}