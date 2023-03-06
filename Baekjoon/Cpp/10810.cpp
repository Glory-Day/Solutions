#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> cache(101, 0);
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;

        for (int i = a; i <= b; i++) {
            cache[i] = c;
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << cache[i] << ' ';
    }
}