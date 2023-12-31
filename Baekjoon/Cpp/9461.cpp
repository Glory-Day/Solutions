#include <iostream>

using namespace std;

typedef long long ll;

ll cache[101];

ll f(int n) {
    if (n < 0) {
        return 0;
    }
    else if (n == 0 || n == 1 || n == 2) {
        return cache[n];
    }
    else if (cache[n]) {
        return cache[n];
    }
    
    return cache[n] = f(n - 3) + f(n - 2);
}

int main() {
    int n;
    cin >> n;

    cache[0] = 0;
    cache[1] = cache[2] = 1;

    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        cout << f(input) << '\n';
    }
}