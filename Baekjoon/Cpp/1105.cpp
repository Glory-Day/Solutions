#include <iostream>
#include <string>

using namespace std;

int main() {
    string l, r;
    cin >> l >> r;

    int answer = 0;
    if (l.size() == r.size()) {
        for (int i = 0; i < l.size(); i++) {
            if (l[i] == '8' && r[i] == '8') {
                answer++;
            }
            else if (l[i] != r[i]) {
                break;
            }
        }
    }

    cout << answer;
}