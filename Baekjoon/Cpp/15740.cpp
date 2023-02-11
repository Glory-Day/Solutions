#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool check(string a, string b) {
    int n = a.size();
    int m = b.size();
    if (n != m) {
        return n > m;
    }

    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]) {
            continue;
        }

        return a[i] > b[i];
    }

    return true;
}

string sum(string a, string b) {
    int n = a.size();
    int m = b.size();
    int l = max(n, m);

    bool chk = false;
    string number(l, '0');
    for (int i = 0; i < l; i++) {
        int tmp = chk;
        chk = false;

        if (i < n) {
            tmp += a[n - i - 1] - '0';
        }

        if (i < m) {
            tmp += b[m - i - 1] - '0';
        }

        if (tmp >= 10) {
            chk = true;
            tmp -= 10;
        }

        number[l - i - 1] = tmp + '0';
    }

    if (chk) {
        number.insert(number.begin(), '1');
    }

    return number;
}

string substract(string a, string b) {
    int n = a.size();
    int m = b.size();

    if (check(a, b) == false) {
        swap(a, b);
        swap(n, m);
    }

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    int cache = 0;
    string number = a;
    for (int i = 0; i < n; i++) {
        int ncache = cache;
        int tmp = (a[i] - '0') - ncache;
        cache = 0;

        if (tmp < 0) {
            cache = 1;
            tmp += 10;
        }

        if (i < m) {
            tmp -= (b[i] - '0');

            if (tmp < 0) {
                cache = 1;
                tmp += 10;
            }
        }

        number[i] = tmp + '0';
    }

    if (cache) {
        int tmp = number[n - 1];
        tmp--;

        number[n - 1] = tmp + '0';
    }

    reverse(number.begin(), number.end());

    int idx = n;
    for (int i = 0; i < n; i++) {
        if (number[i] != '0') {
            idx = i;
            break;
        }
    }

    if (idx == n) {
        return "0";
    }

    return number.substr(idx);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string a, b;
    cin >> a >> b;

    bool chk1 = a[0] != '-';
    bool chk2 = b[0] != '-';
    string answer = "";
    if (chk1 && chk2) {
        answer = sum(a, b);
    }
    else if (chk1 == false && chk2 == false) {
        answer += '-';
        answer += sum(a.substr(1), b.substr(1));
    }
    else if (chk1 == false && chk2) {
        string tmp = substract(a.substr(1), b);
        if (check(a.substr(1), b) && tmp != "0") {
            answer += '-';
            answer += tmp;
        }
        else {
            answer = tmp;
        }
    }
    else if (chk1 && chk2 == false) {
        string tmp = substract(a, b.substr(1));
        if (check(a, b.substr(1)) || tmp == "0") {
            answer = tmp;
        }
        else {
            answer += '-';
            answer += tmp;
        }
    }

    cout << answer;
}