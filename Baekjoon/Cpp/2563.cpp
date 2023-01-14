#include <iostream>
#include <memory.h>

using namespace std;

int main() {
    bool cache[101][101];
    memset(cache, false, sizeof(cache));

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;

        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < 10; k++) {
                cache[a + j][b + k] = true;
            }
        }
    }

    int answer = 0;
    for (int i = 1; i <= 100; i++) {
        for (int j = 1; j <= 100; j++) {
            answer += cache[i][j];
        }
    }

    cout << answer;
}