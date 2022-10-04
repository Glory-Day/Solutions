#include <iostream>
#include <algorithm>

#define ADD 1000000000

using namespace std;

typedef long long ll;

ll cache[1000001];

int main() {
    int n;
    cin >> n;
    
    int len = 0;
    for (int i = 1; i <= n; i++) {
        ll input;
        cin >> input;
        auto it = lower_bound(cache + 1, cache + len + 1, input + ADD);
        *it = input + ADD;
        if (it == cache + len + 1) {
            len++;
        }
    }

    cout << len;
}