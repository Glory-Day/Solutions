#include <iostream>
#include <algorithm>

using namespace std;

int cache[1000001];

int main() {
    int n;
    cin >> n;
    
    int len = 0;
    for (int i = 1; i <= n; i++) {
        int input;
        cin >> input;
        auto it = lower_bound(cache + 1, cache + len + 1, input);
        *it = input;
        if (it == cache + len + 1) {
            len++;
        }
    }

    cout << len;
}