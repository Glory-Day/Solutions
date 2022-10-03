#include <iostream>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int answer = 0;
    if (n > k) {
        while (true) {
            int cnt = 0, tmp = n;
            while (tmp) {
                if (tmp % 2) {
                    cnt++;
                }

                tmp /= 2;
            }

            if (cnt <= k) {
                break;
            }

            answer++, n++;
        }
    }

    cout << answer;
}