#include <iostream>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

struct BigInteger {
    string number;

    BigInteger(string _number) : number(_number) {}

    bool operator<(const BigInteger a) const {
        if (this->number.size() == a.number.size()) {
            return this->number[0] > a.number[0];
        }

        return this->number.size() > a.number.size();
    }
};

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
    int n;
    cin >> n;
    
    priority_queue<BigInteger> pq;
    for (int i = 0; i < n; i++) {
        string input;
        cin >> input;
        if (input != "0") {
            pq.push(BigInteger(input));
        }
    }

    while (pq.size() != 1) {
        BigInteger a = pq.top();
        pq.pop();
        BigInteger b = pq.top();
        pq.pop();

        if (a.number == b.number) {
            pq.push(sum(a.number, b.number));
        }
        else {
            pq.push(b);
        }
    }

    string answer = pq.top().number;
    cout << answer;
}