#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        string m[3];
        for (int i = 0; i < 3; i++) {
            cin >> m[i];
        }

        char answer = '.';
        if (m[0][0] == m[0][1] && m[0][0] == m[0][2]) {
            if (m[0][0] != '.') {
                answer = m[0][0];
            }
        }
        
        if (m[1][0] == m[1][1] && m[1][0] == m[1][2]) {
            if (m[1][0] != '.') {
                answer = m[1][0];
            }
        }
        
        if (m[2][0] == m[2][1] && m[2][0] == m[2][2]) {
            if (m[2][0] != '.') {
                answer = m[2][0];
            }
        }
        
        if (m[0][0] == m[1][0] && m[0][0] == m[2][0]) {
            if (m[0][0] != '.') {
                answer = m[0][0];
            }
        }
        
        if (m[0][1] == m[1][1] && m[0][1] == m[2][1]) {
            if (m[0][1] != '.') {
                answer = m[0][1];
            }
        }
        
        if (m[0][2] == m[1][2] && m[0][2] == m[2][2]) {
            if (m[0][2] != '.') {
                answer = m[0][2];
            }
        }
        
        if (m[0][0] == m[1][1] && m[0][0] == m[2][2]) {
            if (m[0][0] != '.') {
                answer = m[0][0];
            }
        }
        
        if (m[0][2] == m[1][1] && m[0][2] == m[2][0]) {
            if (m[0][2] != '.') {
                answer = m[0][2];
            }
        }

        if (answer == '.') {
            cout << "DRAW\n";
        }
        else {
            cout << answer << '\n';
        }
    }
}