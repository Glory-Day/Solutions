#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

typedef pair<int, int> pi;

bool cache[10001];

void check() {
    for (int i = 2; i < 10001; i++) {
        for (int j = 2; i * j < 10001; j++) {
            if (!cache[i * j]) {
                cache[i * j] = true;
            }
            else {
                continue;
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    cache[1] = true;
    check();

    pi answer = { 0,10001 };
    for (int i = n; i <= m; i++) {
        if (!cache[i]) {
            answer.first += i;
            answer.second = min(answer.second, i);
        }
    }

    if (answer.first == 0 && answer.second == 10001) {
        cout << -1;
    }
    else {
        cout << answer.first << '\n' << answer.second;
    }
}