#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int cache[1001][1001];

int main() {
    string a, b;
    cin >> a >> b;

    string c = " ", d = " ";
    c += a, d += b;

    int mx = -1;
    for (int i = 1; i < c.length(); i++) {
        for (int j = 1; j < d.length(); j++) {
            if (c[i] != d[j]) {
                cache[i][j] = max(cache[i - 1][j], cache[i][j - 1]);
            }
            else cache[i][j] = cache[i - 1][j - 1] + 1;
        }
    }

    int y = c.length() - 1;
    int x = d.length() - 1;
    int ch = cache[y][x];

    cout << cache[y][x] << '\n';

    string answer = "";
    while (ch != 0) {
        if (cache[y - 1][x] == ch) y--;
        else if (cache[y][x - 1] == ch) x--;
        else {
            answer += c[y];
            ch = cache[--y][--x];
        }
    }

    for (auto it = answer.rbegin(); it != answer.rend(); it++) {
        cout << *it;
    }
}