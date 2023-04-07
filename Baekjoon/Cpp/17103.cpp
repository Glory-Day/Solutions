#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<bool> cache(1000001, true);
    cache[0] = cache[1] = false;

    for (int i = 2; i <= 1000000; i++) {
        if (cache[i] == false) {
            continue;
        }

        for (int j = 2; i * j <= 1000000; j++) {
            cache[i * j] = false;
        }
    }

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int answer = 0;
        for (int i = 0; i <= n / 2; i++) {
            int a = i;
            int b = n - i;

            if (cache[a] && cache[b]) {
                answer++;
            }
        }

        cout << answer << '\n';
    }
}