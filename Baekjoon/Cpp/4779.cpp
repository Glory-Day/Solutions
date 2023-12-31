#include <iostream>
#include <cmath>
#include <string>

using namespace std;

void f(string& s, int b, int e) {
    int l = (e - b) / 3;
    if (l == 0) {
        return;
    }
    
    for (int i = b + l; i < b + 2 * l; i++) {
        s[i] = ' ';
    }

    f(s, b, b + l);
    f(s, b + 2 * l, b + 3 * l);
}

int main() {
    int n;
    while (cin >> n) {
        n = pow(3, n);
        
        string s;
        for (int i = 0; i < n; i++) {
            s.push_back('-');    
        }

        f(s, 0, n);

        cout << s << '\n';
    }
}