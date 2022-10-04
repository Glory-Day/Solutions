#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 1; i < n; i++) {
        string s = to_string(i);
        int sum = 0;
        
        for (auto j: s) {
            sum += j - '0';
        }
        sum += i;
        
        if (sum == n) {
            cout << i;
            return 0;
        }
    }

    cout << 0;
}