#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    int i = 666;
    int answer = 0;
    while(n) {
        string s = to_string(i);
        int len = s.size();
        for (int j = 0; j < len - 2; j++) {
            if (s[j] == '6' && s[j + 1] == '6' && s[j + 2] == '6') {
                answer = i;
                n--;
                break;
            }
        }
        i++;
    }

    cout << answer;
}