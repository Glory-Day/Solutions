#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string sum(string a, string b) {
    string c = "";
    int sum = 0;
    while (!a.empty() || !b.empty() || sum) {
        if (!a.empty()) {
            sum += a.back() - '0';
            a.pop_back();
        }

        if (!b.empty()) {
            sum += b.back() - '0';
            b.pop_back();
        }

        c.push_back((sum % 10) + '0');
        sum /= 10;
    }

    reverse(c.begin(), c.end());
    return c;
}

int main() {
    string a, b, c;
    cin >> a >> b >> c;

    string answer = sum(sum(a, b), c);
    cout << answer;
}