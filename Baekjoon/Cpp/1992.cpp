#include <iostream>
#include <string>

using namespace std;

bool map[64][64];

string f(int y, int x, int n) {
    string s = "";

    bool check = true, temp = map[y][x];
    int ny = y;
    for (int i = 0; check && i < n; i++, ny++) {
        int nx = x;
        for (int j = 0; check && j < n; j++, nx++) {
            if (temp != map[ny][nx]) {
                check = false;
            }
        }
    }

    if (check) {
        s.push_back(temp ? '1' : '0');
    }
    else {
        int len = n / 2;
        s.push_back('(');
        s += f(y, x, len);
        s += f(y, x + len, len);
        s += f(y + len, x, len);
        s += f(y + len, x + len, len);
        s.push_back(')');
    }

    return s;
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) {
            map[i][j] = s[j] - '0';
        }
    }

    string answer = f(0, 0, n);

    cout << answer;
}