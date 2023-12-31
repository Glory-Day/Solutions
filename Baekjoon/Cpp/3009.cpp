#include <iostream>
#include <utility>

using namespace std;

int xs[1001];
int ys[1001];

int main() {
    for (int i = 0; i < 3; i++) {
        int x, y;
        cin >> x >> y;
        xs[x]++;
        ys[y]++;
    }

    for (int i = 1; i <= 1000; i++) {
        if (xs[i] == 1) {
            cout << i << ' ';
        }
    }

    for (int i = 1; i <= 1000; i++) {
        if (ys[i] == 1) {
            cout << i << ' ';
        }
    }
}