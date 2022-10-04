#include <iostream>

#define MAX 100000001;

using namespace std;

int cache[1000001];

int main() {
    int n;
    cin >> n;

    cache[2] = cache[3] = 1;

    for (int i = 4; i <= n; i++) {
        int a = (i % 3 == 0) ? cache[i / 3] : MAX;
        int b = (i % 2 == 0) ? cache[i / 2] : MAX;
        int c = cache[i - 1];

        cache[i] = min(a, min(b, c)) + 1;
    }

    cout << cache[n];
}