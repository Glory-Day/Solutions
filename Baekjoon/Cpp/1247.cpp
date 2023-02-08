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

    vector<char> answer;

    int t = 3;
    while (t--) {
        int n;
        cin >> n;

        vector<string> arr;
        for (int i = 0; i < n; i++) {
            string input;
            cin >> input;
            arr.push_back(input);
        }

        string number = arr[0];
        for (int i = 1; i < n; i++) {
            bool a = number[0] != '-';
            bool b = arr[i][0] != '-';

            string tmp = "";
            if (a && b) {
                tmp = sum(number, arr[i]);
            }
            else if (a == false && b == false) {
                tmp += '-';
                tmp += sum(number.substr(1), arr[i].substr(1));
            }
            else if (a == false && b) {
                string ntmp = substract(number.substr(1), arr[i]);
                if (check(number.substr(1), arr[i]) && ntmp != "0") {
                    tmp += '-';
                    tmp += ntmp;
                }
                else {
                    tmp = ntmp;
                }
            }
            else if (a && b == false) {
                string ntmp = substract(number, arr[i].substr(1));
                if (check(number, arr[i].substr(1)) || ntmp == "0") {
                    tmp = ntmp;
                }
                else {
                    tmp += '-';
                    tmp += ntmp;
                }
            }

            number = tmp;
        }

        if (number.front() == '-') {
            answer.push_back('-');
        }
        else if (number == "0") {
            answer.push_back('0');
        }
        else {
            answer.push_back('+');
        }
    }

    for (int i = 0; i < 3; i++) {
        cout << answer[i] << '\n';
    }
}