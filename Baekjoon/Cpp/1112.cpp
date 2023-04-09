#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

int mod(int n, int b) {
    int tmp = n % abs(b);
    if (tmp < 0) {
        tmp += abs(b);
    }

    return tmp;
}

int main() {
    int n, b;
    cin >> n >> b;

    string answer;
    if (n == 0) {
        answer = "0";
    }    
    else {
        int tmp = (b > 0) ? abs(n) : n;
        while (tmp) {
            int t = mod(tmp, b);
            tmp = (tmp - t) / b;
            answer.push_back(t + '0');
        }

        if (n < 0 && b > 0) {
            answer.push_back('-');
        }

        reverse(answer.begin(), answer.end());
    }


    cout << answer;
}