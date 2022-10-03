#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

typedef long long ll;

bool matrix[128][128];

map<string, int> visited;

ll toDigit(string bs) {
    ll d = 0, i = 1;
    for (int j = bs.size() - 1; j >= 0; j--) {
        d += (bs[j] - '0') * i;
        i *= 2;
    }

    return d;
}

string erase(string bs) {
    string nbs = "";

    for (char& i: bs) {
        if (i - '0' > 2) return "";

        if (i != '(' && i != ')') {
            nbs += i;
        }
    }

    return nbs;
}

string f(int y, int x, int n) {
    string s = "";

    bool check = true, temp = matrix[y][x];
    int ny = y;
    for (int i = 0; check && i < n; i++, ny++) {
        int nx = x;
        for (int j = 0; check && j < n; j++, nx++) {
            if (temp != matrix[ny][nx]) {
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

int dfs1(string bs) {
    int lv = 1;
    if (bs.front() == '(') {
        int cnt = 0;
        string nbs = "";
        for (int i = 1; i < bs.size() - 1; i++) {
            if (bs[i] == '(') {
                cnt++;
            }
            else if (bs[i] == ')') {
                cnt--;
            }

            nbs += bs[i];

            if (cnt == 0) {
                lv += dfs1(nbs);
                nbs.clear();
            }
        }
    }

    return lv;
}

int dfs2(string bs) {
    int lv = 1;
    
    if (visited.count(bs)) return 0;

    if (bs.front() == '(') {
        int cnt = 0;
        string nbs = "";
        for (int i = 1; i < bs.size() - 1; i++) {
            if (bs[i] == '(') {
                cnt++;
            }
            else if (bs[i] == ')') {
                cnt--;
            }

            nbs += bs[i];

            if (cnt == 0) {
                lv += dfs2(nbs);
                
                if (nbs.size() != 1) {
                    visited.insert({ nbs,true });
                }

                nbs.clear();
            }
        }
    }

    return lv;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    int l = 1, len = max(n, m);
    while (l < len) l *= 2;

    for (int i = 0; i < n; i++) {
        string input;
        cin >> input;

        for (int j = 0; j < m; j++) {
            matrix[i][j] = input[j] - '0';
        }
    }

    string bs = f(0, 0, l);

    int answer1 = dfs1(bs);
    int answer2 = dfs2(bs);

    cout << answer1 << ' ' << answer2 << '\n';
}