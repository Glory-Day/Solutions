#include <iostream>
#include <vector>

using namespace std;

int cache[15][15];

int sum(int k, int n) {
    if (k == 0) {
        return cache[k][n];
    }
    else if (cache[k][n]) {
        return cache[k][n];
    }
    else {
        int answer = 0;
        for (int i = 1; i <= n; i++) {
            cache[k - 1][i] = sum(k - 1, i);
            answer += cache[k - 1][i];
        }

        return answer;
    }
}

int main() {
    int n;
    cin >> n;

    for (int i = 1; i < 15; i++) {
        cache[0][i] = i;
    }

    sum(15, 14);

    for (int i = 0; i < n; i++) {
        int k, m;
        cin >> k >> m;

        cout << cache[k][m] << '\n';
    }
}