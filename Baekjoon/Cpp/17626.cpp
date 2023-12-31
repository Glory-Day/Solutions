#include <iostream>
#include <algorithm>

using namespace std;

int cache[50001];

int main() {
    int n;
    cin >> n;

    for (int i = 1; i * i <= n; i++) {
        cache[i * i] = 1;
    }

    for (int i = 1; i <= n; i++) {
        if (cache[i] != 0) continue;
        
        cache[i] = cache[i - 1] + 1;
        for (int j = 1; j * j <= i; j++) {
            cache[i] = min(cache[i], cache[j * j] + cache[i - j * j]);
        }
    }

    cout << cache[n];
}