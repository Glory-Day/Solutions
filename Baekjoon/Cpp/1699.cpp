#include <iostream>
#include <algorithm>

using namespace std;

int cache[100001];

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cache[i] = i;
        for (int j = 1; j * j <= i; j++) {
            cache[i] = min(cache[i], cache[i - j * j] + 1);
        }
    }

    cout << cache[n];
}