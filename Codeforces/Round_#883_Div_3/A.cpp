#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int answer = 0;
        for (int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;

            if (a > b) {
                answer++;
            }
        }

        cout << answer << '\n';
    }
}