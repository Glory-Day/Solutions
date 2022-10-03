#include <iostream>

using namespace std;

int cache[12];

int main() {
    int n;
    cin >> n;

    cache[0] = cache[1] = 1;
    cache[2] = 2;

    for (int i = 3; i <= 11; i++) {
        cache[i] = cache[i - 3] + cache[i - 2] + cache[i - 1];
    }

    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        cout << cache[input] << '\n';
    }
}