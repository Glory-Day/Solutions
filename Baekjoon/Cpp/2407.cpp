#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string cache[101][101];

string getBigInteger(string a, string b) {
    string bigInteger;

    int sum = 0;
    while (a.empty() == false || b.empty() == false || sum) {
        if (a.empty() == false) {
            sum += a.back() - '0';
            a.pop_back();
        }

        if (b.empty() == false) {
            sum += b.back() - '0';
            b.pop_back();
        }

        bigInteger.push_back((sum % 10) + '0');
        sum /= 10;
    }

    reverse(bigInteger.begin(), bigInteger.end());

    return bigInteger;
}

string combination(int n, int r) {    
    string& bigInteger = cache[n][r];

    if (n == r || r == 0) {
        return "1";
    }

    if (bigInteger.length() != 0) {
        return bigInteger;
    }

    bigInteger = getBigInteger(combination(n - 1, r - 1), combination(n - 1, r));

    return bigInteger;
}

int main() {
    int n, m;
    cin >> n >> m;

    string answer = combination(n, m);

    cout << answer;
}