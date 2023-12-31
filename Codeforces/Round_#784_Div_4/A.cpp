#include <iostream>

using namespace std;

typedef long long ll;

/*
    문제 설명: 범위가 정해져 있고 rating을 주면 해당 범위에 있는가를 출력하는 문제.
*/

int main() {
    int t;
    cin >> t;

    while (t--) {
        int input;
        cin >> input;

        if (1900 <= input) cout << "Division 1\n";
        else if (1600 <= input && input < 1900) cout << "Division 2\n";
        else if (1400 <= input && input  < 1600) cout << "Division 3\n";
        else cout << "Division 4\n";
    }
}