#include <iostream>

using namespace std;

int main() {
    int sum, n;
    cin >> sum >> n;
    
    
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        sum -= a * b;
    }
    
    if (!sum) cout << "Yes\n";
    else cout << "No\n";
}