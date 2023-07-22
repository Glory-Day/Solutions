#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>
#include <functional>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int answer;
        int tmp = -1;
        for (int i = 1; i <= n; i++) {
            int a, b;
            cin >> a >> b;

            if (a <= 10 && b > tmp) {
                answer = i;
                tmp = b;
            }
        }

        cout << answer << '\n';
    }

    return 0;
}